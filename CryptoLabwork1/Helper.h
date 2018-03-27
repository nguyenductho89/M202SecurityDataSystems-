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
void writeToOuputFile(char *text);
char *readInputFile(void);
int appendString(char **json, const char *format, ...);
#endif /* Helper_h */
