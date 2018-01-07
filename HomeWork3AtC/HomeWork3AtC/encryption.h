#include <stdio.h>
#define FILE_NAME "encryption.txt"

void encrypt(void* ptr, int size);
void decrypt(void* ptr, int size,FILE *f);
void xorAllBytesEncryptDecrypt(void * ptr, int size);
void swapBitsEncrypt(void * ptr, int size, int x);
void swapBitsDecrypt(void * ptr, int size, int x);
void bytesRightRoundMoveEncrypt(void * ptr, int size, int x);
void bytesRightRoundMoveDecrypt(void * ptr, int size, int x);
void printCharAsBinary(char ch);//func for checks