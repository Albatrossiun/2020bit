#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//Ä£ÄâÊµÏÖstrcpy

void mystrcpy(char *arr1,const char* arr2)
{
	while ((*arr1++) = (*arr2++))
	{
		;
	}
}

int main()
{
	char arr1[20] = { 0 };
	char arr2[] = "asdf";
	mystrcpy(arr1,arr2);
	printf("%s\n", arr1);
	return 0;
}