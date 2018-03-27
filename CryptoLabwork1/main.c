//
//  main.c
//  CryptoLabwork1
//
//  Created by Nguyễn Đức Thọ on 3/26/18.
//  Copyright © 2018 Nguyễn Đức Thọ. All rights reserved.
//


#include "Helper.h"
int main (int argc, char *argv[])
{
    char *inputFile, *outputFile;
    if (argc != 3) {
        printf("Usage: aes-encrypt-ecb <input_file> <output_file>\n");
        return 0;
    }
    inputFile = argv[1];
    outputFile = argv[2];
    /************************ Key ************************/
    
    BYTE key[16] = {0x2b, 0x7e, 0x15, 0x16, 0x28, 0xae, 0xd2, 0xa6, 0xab, 0xf7, 0x15, 0x88, 0x09, 0xcf, 0x4f, 0x3c };
    
    /************************ Message ************************/
    
        // Read message from input file
    char *input = readInputFile(inputFile);
        // Convert input to message
    BYTE message[256];
    convertCharToByteArray(message, input);
    
    /************************ Encryption ************************/
    
        // Encrypte message to cipher
    BYTE cipher[16];
    aes_encrypt(cipher, message, key);
    
    /************************ Write Cipher String To Output File ************************/
    
        // Convert Cipher To String
    char *hexCipherString = NULL;
    for (int i = 0; i< 16; i++) {
        appendString(&hexCipherString, "%x ",cipher[i]);
    }
        // Write cipher string to output file
    writeToOuputFile(hexCipherString, outputFile);
    printf("Encryption finish successfully! Check %s for result\n",outputFile);
    return 0;
}


