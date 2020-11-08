#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void _reverse(char* left, char* right)
{
	//	_reverse()�Ĺ��ܣ�����ָ����β���ַ���
	//	�����Ĳ���Ϊ�ַ����͵�ָ��
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
	//	_reverse_part()�Ĺ��ܣ������ַ������á� �������Ĳ���
	char* start = arr;	//	��¼�ַ�������ʼλ��
	char* tmp = arr + strlen(arr) - 1;	//	��¼�ַ�������ֹλ��
	while (*arr)
	{
		char* str = arr;	//	��¼�ַ����е�һ���ֵ���ʼλ��
		char* end = arr;	//	��¼�ַ����е�һ���ֵ���ֹλ��
		while ((*end != ' ') && (*end != '\0'))
		{
			end++;	//	if����Ŀ�ģ�Ϊ���ҵ��� �������Ĳ���
		}
		_reverse(str, end - 1);	//	�����һ����
		if (*end == ' ')
		{
			arr = end + 1;	//	����if��*end == ' '����strָ��ڶ������ֵ���ʼλ��
		}
		else
		{
			arr = end;	//	����else��*end=='\0'���ҵ��ַ��������һλ�����ء�\0����ֹwhileѭ��
		}
	}	//	while()����ǽ��ַ�����ÿ������������
	_reverse(start, tmp);	//	�����ٽ��������ַ��������򼴿�
	return start;
}

int main()
{
	char arr[15] = { 0 };	//	��ʼ��
	gets(arr);		//	�����ַ���ʹ��gets(),�����ַ�ʹ��scanf()
	printf("����ǰ��%s\n", arr);
	printf("���ú�%s\n", _reverse_part(arr));
	return 0;
}