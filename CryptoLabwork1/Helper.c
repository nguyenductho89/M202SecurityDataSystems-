//
//  Helper.c
//  CryptoLabwork1
//
//  Created by Nguyễn Đức Thọ on 3/26/18.
//  Copyright © 2018 Nguyễn Đức Thọ. All rights reserved.
//

#include "Helper.h"

void writeToOuputFile(char *text, char *fileName) {
    FILE * fp;
    fp = fopen (fileName,"ab");
    fprintf (fp, "%s", text);
    fclose (fp);
}
char *readInputFile(char *fileName) {
    char * buffer = 0;
    long length;
    FILE * f = fopen (fileName, "rb");
    
    if (f)
    {
        fseek (f, 0, SEEK_END);
        length = ftell (f);
        fseek (f, 0, SEEK_SET);
        buffer = malloc (length);
        if (buffer)
        {
            fread (buffer, 1, length, f);
        }
        fclose (f);
    }else {
        perror("Check input file");
        exit(-1);
    }
    
    if (buffer)
    {
        return buffer;
    }else {return NULL;}
}
int appendString(char **json, const char *format, ...)
{
    char *str = NULL;
    char *old_json = NULL, *new_json = NULL;
    
    va_list arg_ptr;
    va_start(arg_ptr, format);
    vasprintf(&str, format, arg_ptr);
    
    // save old json
    asprintf(&old_json, "%s", (*json == NULL ? "" : *json));
    
    // calloc new json memory
    new_json = (char *)calloc(strlen(old_json) + strlen(str) + 1, sizeof(char));
    
    strcat(new_json, old_json);
    strcat(new_json, str);
    
    if (*json) free(*json);
    *json = new_json;
    
    free(old_json);
    free(str);
    
    return 0;
}
void convertCharToByteArray(BYTE messageFromFile[],char *input){
    int i = 0;
    char *p = strtok (input, " ");
    while (p != NULL)
    {
        messageFromFile[i++] = (BYTE)strtol(p,NULL,16);
        p = strtok (NULL, " ");
    }
}
void convertInputStringToMessage(BYTE messageFromFile[NumberOfBlock][16],char *input){
    int hexOrdinalInBlock = 0;
    int blockOrdinalInArray = 0;
    //Split input string by a single space
    char *p = strtok (input, " ");
        for(blockOrdinalInArray=0; blockOrdinalInArray<NumberOfBlock; blockOrdinalInArray++) {
            for(hexOrdinalInBlock=0;hexOrdinalInBlock<16;hexOrdinalInBlock++) {
                if (p != NULL) {
                    messageFromFile[blockOrdinalInArray][hexOrdinalInBlock] = (BYTE)strtol(p,NULL,16);
                }
                p = strtok (NULL, " ");
            }
        }
}

char *replace(const char *s, char ch, const char *repl) {
    int count = 0;
    const char *t;
    for(t=s; *t; t++)
        count += (*t == ch);
    size_t rlen = strlen(repl);
    char *res = malloc(strlen(s) + (rlen-1)*count + 1);
    char *ptr = res;
    for(t=s; *t; t++) {
        if(*t == ch) {
            memcpy(ptr, repl, rlen);
            ptr += rlen;
        } else {
            *ptr++ = *t;
        }
    }
    *ptr = 0;
    return res;
}
