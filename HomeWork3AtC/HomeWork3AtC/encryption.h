#ifndef __ENCYPTION_H
#define __ENCYPTION_H
#define NUMBER_OF_BITS_IN_BYTE 8
#define MAX_SIZE_RAND 7
#define ENCRYPT_TEXT_FILE_NAME "encryption.txt"
#define NUMBERS_RANGE 8
#define ecryptNum 255
#include <stdio.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h> 


void encrypt(void* ptr, int size, int x);
void decrypt(void* ptr, int size, int x);
void xorAllBytesEncryptDecrypt(void * ptr, int size);
void swapBitsEncryptDecrypt(void * ptr, int size, int x);
void bytesRightRoundMoveEncrypt(void * ptr, int size, int x);
void bytesRightRoundMoveDecrypt(void * ptr, int size, int x);
#endif