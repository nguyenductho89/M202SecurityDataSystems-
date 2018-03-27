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
    char *inputFile, *outputFile, *mode;
    if (argc != 4) {
        printf("Usage: aes-encrypt-ecb <input_file> <output_file> encrypt(or decrypt) \n");
        return 0;
    }
    inputFile = argv[1];
    outputFile = argv[2];
    mode = argv[3];
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
    if (strcmp(mode, "encrypt")) {
        printf("/************************ start encrypt ************************/");
        aes_encrypt(cipher, message, key);
    } else if(strcmp(mode, "decrypt")) {
        printf("/************************ start decrypt ************************/");
        aes_decrypt(cipher, message, key);
    }else {
        perror("Choose encrypt or decrypt mode");
        exit(-1);
    }
    
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


