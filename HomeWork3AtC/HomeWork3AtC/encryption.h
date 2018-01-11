#include <stdio.h>
#define ENCRYPT_FILE_NAME "encryption.txt"

void encrypt(void* ptr, int size);
void decrypt(void* ptr, int size, char* fileName);
void xorAllBytesEncryptDecrypt(void * ptr, int size);
void swapBitsEncryptDecrypt(void * ptr, int size, int x);
void bytesRightRoundMoveEncrypt(void * ptr, int size, int x);
void bytesRightRoundMoveDecrypt(void * ptr, int size, int x);
void printCharAsBinary(char ch);//func for checks