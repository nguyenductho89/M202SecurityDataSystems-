//
//  testFunctions.c
//  CryptoLabwork1
//
//  Created by Nguyễn Đức Thọ on 3/27/18.
//  Copyright © 2018 Nguyễn Đức Thọ. All rights reserved.
//


#include "Helper.h"
int main (int argc, char *argv[])
{


    
    char *inputFile, *outputFile, *mode;
    inputFile = "padding16copy";
    outputFile = "pad16en";
    mode = "encrypt";
    /************************ Key ************************/
    
    BYTE key[16] = {0x2b, 0x7e, 0x15, 0x16, 0x28, 0xae, 0xd2, 0xa6, 0xab, 0xf7, 0x15, 0x88, 0x09, 0xcf, 0x4f, 0x3c };
    
    /************************ Message ************************/
    
    // Read message from input file
    char *input = readInputFile(inputFile);
    printf("/************************ Input from input file ************************/\n");
    printf("%s\n", input);
    printf("/************************************************************************/\n");
    // Convert input to message
    //BYTE message[256];
    //convertCharToByteArray(message, input);
    BYTE message[NumberOfBlock][16];
    convertCharToByteArray2(message, input);
    printf("/************************ Message ************************/\n");
    for (int i = 0; i<NumberOfBlock; i++) {
        for (int j = 0; j < 16; j++) {
            printf("i:%d j:%d %x\n",i,j, message[i][j]);
        }
    }
    printf("/************************************************************************/\n");
    /************************ Encryption ************************/
    
    // Encrypte message to cipher
    BYTE cipher[16];
    if (!strcmp(mode, "encrypt")) {
        printf("/************************ start encrypt mode mode ************************/\n");
        printf("/************************ Cipher hex string ************************/\n");
        for (int i = 0; i<NumberOfBlock; i++) {
            aes_encrypt(cipher, message[i], key);
            /************************ Write Cipher String To Output File ************************/
            
            // Convert Cipher To String
            char *hexCipherString = NULL;
            for (int i = 0; i< 16; i++) {
                appendString(&hexCipherString, "%x ",cipher[i]);
            }
            appendString(&hexCipherString, "\n");
            // Write cipher string to output file
            writeToOuputFile(hexCipherString, outputFile);
            printf("%s\n", hexCipherString);
           
        }
         printf("/************************************************************************/\n");
    } else if(!strcmp(mode, "decrypt")) {
        printf("/************************ start decrypt ************************/\n");
        aes_decrypt(cipher, message, key);
    }else {
        perror("Choose encrypt or decrypt mode\n");
        exit(-1);
    }
    printf("/************************ '%s' finish successfully! Check '%s' for result ************************/\n",mode,outputFile);
    return 0;
}
