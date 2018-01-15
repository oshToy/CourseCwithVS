#include "encryption.h"


void encrypt(void * ptr, int size, int x) {//3
	swapBitsEncryptDecrypt(ptr, size, x);
	xorAllBytesEncryptDecrypt(ptr, size);
	bytesRightRoundMoveEncrypt(ptr, size, x);
}

void decrypt(void * ptr, int size, int x) {
	bytesRightRoundMoveDecrypt(ptr, size, x);
	xorAllBytesEncryptDecrypt(ptr, size);
	swapBitsEncryptDecrypt(ptr, size, x);
}
void bytesRightRoundMoveEncrypt(void * ptr, int size, int x) {//3C
	for (int i = 0; i < size; i++) {
		unsigned char* temp = (char*)ptr + i;
		unsigned char originalByte = *((char*)ptr + i);
		*temp = *temp >> x;
		originalByte = originalByte << (NUMBER_OF_BITS_IN_BYTE - x);
		*temp = *temp | originalByte;//final result
	}

}
void bytesRightRoundMoveDecrypt(void * ptr, int size, int x) {//4
	bytesRightRoundMoveEncrypt(ptr, size, NUMBER_OF_BITS_IN_BYTE - x);

}
void xorAllBytesEncryptDecrypt(void * ptr, int size) {//3B
	for (int i = 0; i < size; i++) {
		unsigned char* temp = (char*)ptr + i;
		*temp = *temp ^ ecryptNum;
	}
}
void swapBitsEncryptDecrypt(void * ptr, int size, int x) {//3a
	if (x == MAX_SIZE_RAND) {
		x = 0;
	}
	for (int i = 0; i < size; i++) {
		unsigned char* temp = (char*)ptr + i;
		unsigned char originalByte = *((char*)ptr + i);

		*temp = *temp >> x;
		int bitOnX = *temp % 2;
		*temp = *temp >> 1;
		int bitOnXplus1 = *temp % 2;
		if (bitOnX != bitOnXplus1) {//check if need to swap
			*temp = *temp ^ 1;
			*temp = *temp << 1;
			if (bitOnXplus1 == 1) {// if its 0 , its swap already
				*temp = *temp ^ 1;
			}
			*temp = *temp << x;
		}
		else {//if the equals no need to change
			*temp = *temp << 1;
			if (bitOnX == 1) {
				*temp = *temp ^ 1;
			}
			*temp = *temp << (x);
		}
		unsigned char temp2ForOr = originalByte;
		temp2ForOr = temp2ForOr << (NUMBER_OF_BITS_IN_BYTE - x);//i want to put 0 on all the byte except th bits that lower than x
		temp2ForOr = temp2ForOr >> (NUMBER_OF_BITS_IN_BYTE - x);
		*temp = *temp | temp2ForOr;//final result

	}

}


