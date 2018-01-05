#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int getAsciiSum(const char* str) {
	int length = strlen(str);
	int res = 0;
	for (int i = 0; i < length; i++)
	{
		res += str[i];
	}
	return res;
}
int sumAllStrings(const char* arr[], int size, int(*getSum)(const char*)) {
	
	for (int i = 0; i < size; i++)
	{
		printf("%d\t",getSum(arr[i]));
	}

}

int main() {
	char* arr[] = {"yoyo","a" ,"dc" ,"as" };
	int size = sizeof(arr) / sizeof(arr[0]);
	sumAllStrings(arr, size, getAsciiSum);
	printf("\n");
	sumAllStrings(arr, size, strlen);
	system("pause");
}