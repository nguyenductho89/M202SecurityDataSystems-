//
//  aes.h
//  CryptoLabwork1
//
//  Created by Nguyễn Đức Thọ on 3/26/18.
//  Copyright © 2018 Nguyễn Đức Thọ. All rights reserved.
//

#ifndef aes_h
#define aes_h
#define ENCRYPT 1
#define DECRYPT 2

#define MULT_2(x) (  xtime(x)  )
#define MULT_3(x) (  xtime(x) ^ (x)  )
#define MULT_9(x) (  xtime(xtime(xtime(x))) ^ (x)  )
#define MULT_B(x) (  xtime(xtime(xtime(x)) ^ (x)) ^ (x)  )
#define MULT_D(x) (  xtime(xtime(xtime(x) ^ (x))) ^ (x)  )
#define MULT_E(x) (  xtime(xtime(xtime(x) ^ (x)) ^ (x))  )

typedef unsigned char BYTE;
void aes_encrypt(BYTE* cipher, BYTE* message, BYTE* key);
void aes_decrypt(BYTE* message, BYTE* cipher, BYTE* key);
void key_schedule(BYTE* expanded_key, BYTE* key);
void add_round_key(BYTE* state, BYTE* round_key);
void sub_bytes(BYTE* state, unsigned int mode);
void shift_rows(BYTE* state, unsigned int mode);
void mix_columns(BYTE* state, unsigned int mode);
BYTE xtime(BYTE);
void display_state(BYTE* state, char *label);

#endif /* aes_h */
