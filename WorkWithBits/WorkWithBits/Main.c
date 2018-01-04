#include <stdio.h>
#include <stdlib.h>
#define DAYBITS 5
#define MONTHBITS 4
#define YEARBITS 7
typedef struct
{
	int day, month, year;
} Date;

unsigned char* compressedDate(const Date* date);
Date unCompressedDate(unsigned char* date);

void printCharAsBinary(char ch);
unsigned int createMask(int left, int right);

void main()
{
	Date origDate = { 7, 2, 2010 }, newDate;
	unsigned char* strCompressed = compressedDate(&origDate);

	// for debug: check the array:
	printf("The compressed data:\n");
	printCharAsBinary(strCompressed[2]);
	printCharAsBinary(strCompressed[1]);
	printCharAsBinary(strCompressed[0]);

	newDate = unCompressedDate(strCompressed);

	printf("\nThe read date is %d/%d/%d\n",
		newDate.day, newDate.month, newDate.year);

	free(strCompressed);

	system("pause");
}

unsigned char* compressedDate(const Date* date)
{
	char* res = (char*)calloc(3, sizeof(char));
	res[0] = date->day;
	unsigned char monthMask = date->month;
	monthMask <<= MONTHBITS;
	res[0] = res[0] | monthMask;
	monthMask = date->month;
	monthMask >>= MONTHBITS-1;//1 FOR 2 CHAR
	res[1] = monthMask;
	unsigned char yearMask = date->year;
	printCharAsBinary(date->year);
	yearMask <<= 1;
	res[1] = res[1] | yearMask;	
	yearMask = (date->year>>7);
	res[2] = yearMask;

	return res;

}

Date unCompressedDate(unsigned char* data)
{
	int day = data[0] % 16;
	int month = data[0] /16;
	month = month | (data[1]%2 << 3);
	int year = data[1] / 2;
	year = year | (data[2] << 7);


	Date res = {day, month, year };

		return res;
}

void printCharAsBinary(char ch)
{
	int i;
	unsigned char temp;
	for (i = 0; i < 8; i++)
	{
		temp = ch << i;
		temp = temp >> 7;
		printf("%d", temp);
	}
	printf(" ");
}

// create mask with 1's between left-right (including)
unsigned int createMask(int left, int right)
{
	return (1 << (left + 1)) - (1 << right);
}