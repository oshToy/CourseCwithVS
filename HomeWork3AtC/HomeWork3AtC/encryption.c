#include "encryption.h"
#include "encryption.h" 
#include <time.h>
#include <stdio.h>
void encrypt(void * ptr, int size)//3
{

	FILE *file = fopen(FILE_NAME, "w");
	if (file == NULL)//check if open file failed
	{
		printf("Failed opening the file. Exiting!\n");
		return;
	}


	srand(time(NULL));
	int x = rand() % 8;
	
	fprintf(file,"%d",x);
	fclose(file);
	swapBitsEncrypt(ptr, size, x);
	xorAllBytesEncryptDecrypt(ptr, size);
	bytesRightRoundMoveEncrypt(ptr, size, x);

}

void decrypt(void * ptr, int size, FILE * f) {

	FILE *file = fopen(FILE_NAME, "r");
	int x=0;
	fscanf(file, "%d", x);
	fclose(file);

	swapBitsEncrypt(ptr, size, x);
	xorAllBytesEncryptDecrypt(ptr, size);
	bytesRightRoundMoveDecrypt(ptr, size, x);//need to fill

}
void bytesRightRoundMoveEncrypt(void * ptr, int size, int x) {//3C
	for (int i = 0; i < size; i++) {
		printCharAsBinary(*((char*)ptr + i));
		unsigned char* temp = (char*)ptr + i;
		unsigned char originalByte = *((char*)ptr + i);
		*temp = *temp >> x;
		originalByte = originalByte << (8 - x);
		*temp = *temp | originalByte;//final result
		printCharAsBinary(*((char*)ptr + i));
	}

}
void bytesRightRoundMoveDecrypt(void * ptr, int size, int x) {//4
	bytesRightRoundMoveEncrypt(ptr, size, 8-x);

}
void xorAllBytesEncryptDecrypt(void * ptr, int size) {//3B
	for (int i = 0; i < size; i++) {
		printCharAsBinary(*((char*)ptr + i));
		unsigned char* temp = (char*)ptr + i;
		*temp = *temp ^ 255;
		printCharAsBinary(*((char*)ptr + i));
	}
}
void swapBitsEncrypt(void * ptr, int size, int x) {//3a
	for (int i = 0; i < size; i++) {
		printCharAsBinary(*((char*)ptr + i));
		unsigned char* temp = (char*)ptr + i;
		unsigned char originalByte = *((char*)ptr + i);
		if (x != 7) {
			*temp = *temp >> x;
			int bitOnX = *temp % 2;
			*temp = *temp >> 1;
			int bitOnXplus1 = *temp % 2;
			if (bitOnX = !bitOnXplus1) {//check if need to swap
				*temp = *temp ^ 1;
				*temp = *temp << 1;
				if (bitOnXplus1 == 1) {// if its 0 , its swap already
					*temp = *temp ^ 1;
				}
				*temp = *temp << x;
			}
			else {//if the equals no need to change
				*temp = *temp << (x + 1);
			}
			unsigned char temp2ForOr = originalByte;
			temp2ForOr = temp2ForOr << (8 - x);//i want to put 0 on all the byte except th bits that lower than x
			temp2ForOr = temp2ForOr  >> (8 - x);
			*temp = *temp | temp2ForOr;//final result
		}
		else {
			*temp = *temp & 127;//and with 01111111
		}
		printCharAsBinary(*((char*)ptr + i));
	}
}
void swapBitsDecrypt(void * ptr, int size, int x) {

}
void printCharAsBinary(char ch)//func for checks
{
	int i;
	unsigned char temp;
	for (i = 0; i < 8; i++)
	{
		temp = ch << i;
		temp = temp >> 7;
		printf("%d", temp);
	}
	printf(" \n");
}