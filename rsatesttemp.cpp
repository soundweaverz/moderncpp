#include <string>
#include <iostream>

#include <openssl/bn.h>
#include <openssl/rsa.h>
#include <openssl/pem.h>
#include <openssl/bio.h>
#include <openssl/x509.h>

int generatersa(RSA *rsa, EVP_PKEY *pkey)
{
    BIGNUM *bn = BN_new();

    if(!BN_set_word(bn, RSA_F4))
    {
        std::cerr << "Could not set word." << std::endl;
        return 0;
    }

    // Generate Key
    if(!RSA_generate_key_ex(rsa, 2048, bn, NULL))
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

    // Cleanup
    BN_free(bn);

    return 1;
}

int writersa(EVP_PKEY *pkey, std::string passphrase)
{
    BIO *pem = BIO_new_file("rsa-private.pem","w");

    // Write private key in PKCS PEM
    if(!PEM_write_bio_PKCS8PrivateKey(pem, pkey,
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

    // Cleanup
    BIO_free(pem);

    return 1;
}
int rsaencrypt(RSA *rsa, std::string cleantext);
int readrsa(RSA *rsa, EVP_PKEY *pkey, std::string passphrase)
{
    BIO *pemread = BIO_new_file("rsa-private.pem","r");
    BIO *pemwrite = BIO_new_file("rsa-private2.pem","w");
 
    PEM_read_bio_PrivateKey(pemread, &pkey, 0, const_cast<char*>(passphrase.c_str()));

    // Write private key in PKCS PEM
    if(!PEM_write_bio_PKCS8PrivateKey(pemwrite, pkey,
        EVP_des_ede3_cbc(), const_cast<char*>(passphrase.c_str()),
        passphrase.size(), NULL, NULL))
    {
        std::cerr << "Could not convert RSA to PKEY." << std::endl;
        return 0;
    }
    std::cout << "Successfully read RSA Private Key." << std::endl;

    // get rsa from pkey
    rsa = EVP_PKEY_get1_RSA(pkey);
    rsaencrypt(rsa, passphrase);

    // Cleanup
    BIO_free(pemread);
    BIO_free(pemwrite);

    return 1;
}

int rsaencrypt(RSA *rsa, std::string cleantext)
{
    // string allocation
    unsigned char *from = (unsigned char *) cleantext.c_str();
    std::cout << from << std::endl;
    unsigned char to[512] = "";

    // encryption
    RSA_private_encrypt(cleantext.size(), from, to, rsa, RSA_PKCS1_PADDING);

    // cipher output
    std::cout << to << std::endl;

    // writebio
    BIO *cipher = BIO_new_file("ciphertext.txt","w");
    BIO_write(cipher, to, RSA_size(rsa));

    // cleanup
    BIO_free(cipher);

    return 1;
}

int rsadecrypt(RSA *rsa)
{
    // create buffer for ciphertext
    unsigned char ciphertext[256] = "";
    unsigned char to[256] = "";

    // writebio
    BIO *cipher = BIO_new_file("ciphertext.txt","r");
    int rc = 0;
    rc = BIO_read(cipher, ciphertext, 256);
    std::cout << rc << std::endl;

    // output cipher
    std::cout << ciphertext << std::endl;

    // decrypt cipher
    RSA_public_decrypt(256, ciphertext, to, rsa, RSA_PKCS1_PADDING);

    std::cout << to << std::endl;

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

    RSA *rsa = RSA_new();
    EVP_PKEY *pkey = EVP_PKEY_new();
    RSA *rsa2 = RSA_new();
    EVP_PKEY *pkey2 = EVP_PKEY_new();

    if(!generatersa(rsa, pkey))
    {
        return 1;
    }

    if(!writersa(pkey, passphrase))
    {
        return 1;
    }

    if(!readrsa(rsa2, pkey2, passphrase))
    {
        return 1;
    }

    std::cout << "All RSA generation tasks successful." << std::endl;

    std::string text {};
    std::cout << "Please enter a text to be encrypted: ";
    std::getline(std::cin, text);

    if(!rsaencrypt(rsa, text))
    {
        return 1;
    }

    if(!rsadecrypt(rsa))
    {
        return 1;
    }
    
    // Cleanup
    std::cout << "Cleanup of all pointers..." << std::endl;
    RSA_free(rsa);
    RSA_free(rsa2);
    EVP_PKEY_free(pkey);
    EVP_PKEY_free(pkey);

    // Finally
    std::cout << "At least nothing went wrong." << std::endl;

    return 0;
}
