#include <string>
#include <iostream>
#include <memory>
using std::unique_ptr;

#include <openssl/bn.h>
#include <openssl/rsa.h>
#include <openssl/pem.h>
#include <openssl/bio.h>
#include <openssl/x509.h>

using BN_ptr = std::unique_ptr<BIGNUM, decltype(&::BN_free)>;
using RSA_ptr = std::unique_ptr<RSA, decltype(&::RSA_free)>;
using EVP_KEY_ptr = std::unique_ptr<EVP_PKEY, decltype(&::EVP_PKEY_free)>;
using BIO_FILE_ptr = std::unique_ptr<BIO, decltype(&::BIO_free)>;

int generatersa(RSA *rsa, EVP_PKEY *pkey)
{
    BN_ptr bn(BN_new(), ::BN_free);

    if(!BN_set_word(bn.get(), RSA_F4))
    {
        std::cerr << "Could not set word." << std::endl;
        return 0;
    }

    // Generate Key
    if(!RSA_generate_key_ex(rsa, 2048, bn.get(), NULL))
    {
        std::cerr << "Could not generate key." << std::endl;
        return 0;
    }

    // Convert RSA to PKEY
    if(!EVP_PKEY_set1_RSA(pkey, rsa))
    {
        std::cerr << "Could not convert RSA to PKEY." << std::endl;
        return 0;
    }

    std::cout << "Successfully created RSA Private Key." << std::endl;
    return 1;
}

int writersa(EVP_PKEY *pkey, std::string passphrase)
{
    BIO_FILE_ptr pem(BIO_new_file("rsa-private.pem","w"), ::BIO_free);

    // Write private key in PKCS PEM
    if(!PEM_write_bio_PKCS8PrivateKey(pem.get(), pkey,
        EVP_des_ede3_cbc(), const_cast<char*>(passphrase.c_str()),
        passphrase.size(), NULL, NULL))
    {
        std::cerr << "Could not convert RSA to PKEY." << std::endl;
        return 0;
    }
    #ifdef DEBUG
     std::cout << "Successfully wrote RSA Private Key with the passphrase \""
         << passphrase << "\"." << std::endl;
    #else
     std::cout << "Successfully wrote RSA Private Key." << std::endl;
    #endif

    return 1;
}

int readrsa(RSA *rsa, EVP_PKEY *pkey, std::string passphrase)
{
    BIO_FILE_ptr pem(BIO_new_file("rsa-private.pem","r"), ::BIO_free);

    if(!PEM_read_bio_PrivateKey(pem.get(), &pkey, 0, const_cast<char*>(passphrase.c_str())))
    {
        return 0;
    }

    std::cout << "Successfully read RSA Private Key." << std::endl;
    return 1;
}

int rsaencrypt(RSA *rsa, EVP_PKEY *pkey)
{
    // string allocation
    std::string cleantext = "This is a test.";
    unsigned char *from = (unsigned char *) cleantext.c_str();
    unsigned char to[2048] = "";

    // encryption
    RSA_public_encrypt(cleantext.size(), from, to, rsa, RSA_PKCS1_PADDING);

    // cipher output
    std::cout << to << std::endl;

    // writebio
    // BIO_FILE_ptr cipher(BIO_new_file("ciphertext.txt","w"), ::BIO_free);
    // size_t *written = 0;
    // BIO_write_ex(cipher.get(), const_cast<unsigned char*>(to), (size_t) 2048, written);

    // std::cout << "\n" << (long long signed int) written << std::endl;

    return 1;
}

int main(int argc, const char* argv[])
{
    std::string passphrase;
    if(argc > 1)
    {
        passphrase.assign(argv[1]);
        #ifdef DEBUG
         std::cout << argc << std::endl;
         std::cout << passphrase << std::endl;
        #endif
    }
    else
    {
        std::cout << "Please enter a passphrase: ";
        std::getline(std::cin, passphrase);
    }

    RSA_ptr rsa(RSA_new(), ::RSA_free);
    EVP_KEY_ptr pkey(EVP_PKEY_new(), ::EVP_PKEY_free);

    if(!generatersa(rsa.get(), pkey.get()))
    {
        return 1;
    }

    if(!writersa(pkey.get(), passphrase))
    {
        return 1;
    }

    RSA_ptr rsa2(RSA_new(), ::RSA_free);
    EVP_KEY_ptr pkey2(EVP_PKEY_new(), ::EVP_PKEY_free);

    if(!readrsa(rsa2.get(), pkey2.get(), passphrase))
    {
        return 1;
    }

    std::cout << "All RSA generation tasks successful." << std::endl;

    std::string text {};
    std::cout << "Please enter a text to be encrypted: ";
    std::getline(std::cin, text);

    std::basic_string<unsigned char> cleantext;

    if(!rsaencrypt(rsa.get(), pkey.get()))
    {
        return 1;
    }
    
    std::cout << "At least nothing went wrong." << std::endl;
}
