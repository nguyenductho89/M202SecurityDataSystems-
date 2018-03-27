//
//  main.c
//  CryptoLabwork1
//
//  Created by Nguyễn Đức Thọ on 3/26/18.
//  Copyright © 2018 Nguyễn Đức Thọ. All rights reserved.
//

#include <stdio.h>
#include "Helper.h"
#include "aes.h"
int main ()
{
    /************************ Key ************************/
    BYTE key[16] = {0x2b, 0x7e, 0x15, 0x16, 0x28, 0xae, 0xd2, 0xa6, 0xab, 0xf7, 0x15, 0x88, 0x09, 0xcf, 0x4f, 0x3c };
    
    /************************ Message ************************/
    BYTE message[16]  = {0x32, 0x43, 0xf6, 0xa8, 0x88, 0x5a, 0x30, 0x8d, 0x31, 0x31, 0x98, 0xa2, 0xe0, 0x37, 0x07, 0x34};
    BYTE messageFromFile = NULL;
    char *buf = readInputFile();
    int i = 0;
    char *p = strtok (buf, " ");
    char *array[16];
    
    while (p != NULL)
    {
        array[i++] = p;
        p = strtok (NULL, " ");
    }
    
    for (i = 0; i < 16; ++i)
        printf("%s\n", array[i]);

 
    /************************ Encryption ************************/
    BYTE cipher[16];
    aes_encrypt(cipher, message, key);
    
    /************************ Convert Cipher To String ************************/
    char *hexCipherString = NULL;
    for (int i = 0; i< 16; i++) {
        //printf("%x ",cipher[i]);
        appendString(&hexCipherString, "%x ",cipher[i]);
    }
    
    /************************ Write Cipher String To Output File ************************/
    writeToOuputFile(hexCipherString);
    
    return 0;
}
