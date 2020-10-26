#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void* mymemmove(void* arr1, const void* arr2, size_t count)
{
	void* ret = arr1;
	while (count--)
	{
		*(char*)arr1 = *(char*)arr2;
		((char*)arr1)++;
		((char*)arr2)++;
	}
	return ret;
}

int main()
{
	int arr2[8] = { 1,2,3,4,5,6,7,8 };
	int* p = NULL;
	mymemmove(arr2+3, arr2, 20);
	return 0;
}