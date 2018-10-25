#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

// #include <openssl/bio.h>

int main()
{
    FILE *ptr;
    ptr = fopen("ciphertext.txt","rb");
    unsigned char cstringbuf[256] = "";
    fread(cstringbuf, sizeof(cstringbuf),1,ptr);
    

    return 0;
}
