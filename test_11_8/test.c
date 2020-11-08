#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void _reverse(char* left, char* right)
{
	//	_reverse()的功能：逆序指定首尾的字符串
	//	函数的参数为字符类型的指针
	while (left < right)
	{
		char tmp = *left;
		*left = *right;
		*right = tmp;
		left++;
		right--;
	}
}

char* _reverse_part(char* arr)
{
	//	_reverse_part()的功能：逆序字符串中用‘ ’隔开的部分
	char* start = arr;	//	记录字符串的起始位置
	char* tmp = arr + strlen(arr) - 1;	//	记录字符串的终止位置
	while (*arr)
	{
		char* str = arr;	//	记录字符串中第一部分的起始位置
		char* end = arr;	//	记录字符串中第一部分的终止位置
		while ((*end != ' ') && (*end != '\0'))
		{
			end++;	//	if语句的目的：为了找到‘ ’隔开的部分
		}
		_reverse(str, end - 1);	//	逆序第一部分
		if (*end == ' ')
		{
			arr = end + 1;	//	进入if，*end == ' '，令str指向第二个部分的起始位置
		}
		else
		{
			arr = end;	//	进入else，*end=='\0'，找到字符串的最后一位，返回‘\0’终止while循环
		}
	}	//	while()语句是将字符串的每个部分先逆序
	_reverse(start, tmp);	//	这里再进行整个字符串的逆序即可
	return start;
}

int main()
{
	char arr[15] = { 0 };	//	初始化
	gets(arr);		//	输入字符串使用gets(),输入字符使用scanf()
	printf("倒置前：%s\n", arr);
	printf("倒置后：%s\n", _reverse_part(arr));
	return 0;
}