#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//Ä£ÄâÊµÏÖmemmove
void* my_memmove(void* arr1, const void* arr2, size_t count)
{
	if (arr1 < arr2)
	{
		while (count--)
		{
			*(char*)arr1 = *(char*)arr2;
			arr1 = (char*)arr1 + 1;
			arr2 = (char*)arr2 + 1;
		}
	}
	else
	{
		while (count--)
		{
			*((char*)arr1 + count) = *((char*)arr2 + count);
		}
	}
}

int main()
{
	int arr2[8] = { 1, 2, 4, 3, 5 ,9 ,8 ,6 };
	my_memmove(arr2, arr2+1, 12);
	return 0;
}
