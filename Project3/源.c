#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
//ʵ��һ�����������������ַ����е�k���ַ���
//���磺
//ABCD����һ���ַ��õ�BCDA
//ABCD���������ַ�

void left_handed(char *p,int size,int count)
{
	int left = 0;
	int right = size - 1;
	while (count)
	{
		char tmp = p[0];
		int i = 0;
		for (i = 1; i <= size - 1; i++)
		{
			p[i - 1] = p[i];
		}
		p[size - 1] = tmp;
		count--;
	}
	int j = 0;
	for (j = 0; j < size; j++)
	{
		printf("%c", p[j]);
	}
	printf("\n");
}

int main()
{
	int size;
	int count;
	int j = 0;
	printf("��������������ĸ�����  ");
	scanf("%d", &count);
	char arr[] = "ABCDEF";
	size = sizeof(arr) / sizeof(arr[3]) - 1;
	for (j = 0; j < size; j++)
	{
		printf("%c", arr[j]);
	}
	printf("\n");
	left_handed(arr,size,count);
	return 0;
}