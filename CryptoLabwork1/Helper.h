//
//  Helper.h
//  CryptoLabwork1
//
//  Created by Nguyễn Đức Thọ on 3/26/18.
//  Copyright © 2018 Nguyễn Đức Thọ. All rights reserved.
//

#ifndef Helper_h
#define Helper_h

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#include "aes.h"
void writeToOuputFile(char *text, char *fileName);
char *readInputFile(char *fileName);
int appendString(char **json, const char *format, ...);
void convertCharToByteArray(BYTE messageFromFile[],char *input);
#endif /* Helper_h */
