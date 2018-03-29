//
//  testFunctions.c
//  CryptoLabwork1
//
//  Created by Nguyễn Đức Thọ on 3/27/18.
//  Copyright © 2018 Nguyễn Đức Thọ. All rights reserved.
//


#include "Helper.h"
void operatingWithMode(char *mode,char *input, char *inputFile, char *outputFile){
    /************************ Key ************************/
    
    BYTE key[16] = {0x2b, 0x7e, 0x15, 0x16, 0x28, 0xae, 0xd2, 0xa6, 0xab, 0xf7, 0x15, 0x88, 0x09, 0xcf, 0x4f, 0x3c };
    // Convert input to message
    BYTE messageBlock[NumberOfBlock][16];
    convertInputStringToMessageBlocks(messageBlock, input);
    printf("/************************ Message ************************/\n");
    for (int i = 0; i<NumberOfBlock; i++) {
        for (int j = 0; j < 16; j++) {
            printf("i:%d j:%d %x\n",i,j, messageBlock[i][j]);
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
            aes_encrypt(cipher, messageBlock[i], key);
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
        aes_decrypt(cipher, messageBlock, key);
    }else {
        perror("Choose encrypt or decrypt mode\n");
        exit(-1);
    }
    printf("/************************ '%s' finish successfully! Check '%s' for result ************************/\n",mode,outputFile);
}

int main (int argc, char *argv[])
{
    char *inputFile, *outputFile, *mode;
    //inputFile = "logo.png";
    inputFile = "padding16";
    outputFile = "pad16en";
    mode = "encrypt";

    //String input
//    /************************ Message ************************/
//    // Read message from input file
//    char *input = readInputFile(inputFile);
//    //Replace line break with a single space
//    //input = replace(input, '\n', " "); //Use when input file contains \n
//    printf("/************************ Input from input file ************************/\n");
//    printf("%s\n", input);
//    printf("/************************************************************************/\n");
//
//    operatingWithMode(mode, input, inputFile, outputFile);
    
    //Hex input
//    FILE *file = NULL;
//    unsigned char buffer[1024];  // array of bytes, not pointers-to-bytes
//    size_t bytesRead = 0;
//
//    file = fopen(inputFile, "rb");
//
//    if (file != NULL)
//    {
//        // read up to sizeof(buffer) bytes
//        while ((bytesRead = fread(buffer, 1, sizeof(buffer), file)) > 0)
//        {
//            // process bytesRead worth of data in buffer
//            printf("%x \n", buffer);
//        }
//    }
//
    FILE *fp;
    char c[] = "this is tutorialspoint";
    char buffer[100];
    
    /* Open file for both reading and writing */
    fp = fopen("file.txt", "w+");
    
    /* Write data to the file */
    fwrite(c, strlen(c) + 1, 1, fp);
    
    /* Seek to the beginning of the file */
    fseek(fp, 0, SEEK_SET);
    
    /* Read and display data */
    fread(buffer, strlen(c)+1, 1, fp);
    printf("%s\n", buffer);
    fclose(fp);
    

    return 0;
}


