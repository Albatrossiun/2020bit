#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define ROW 4
#define COL 4
//��һ�����־��󣬾����ÿ�д������ǵ����ģ�������ϵ����ǵ�����
//���д�����������ľ����в���ĳ�������Ƿ���ڡ�
int Yang(int arr[ROW][COL], int val)
{
	int i = 0;
	int j = COL - 1;
	int tmp = arr[i][j];
	while (1)
	{
		if (tmp == val)
		{
			return 1;
		}
		else if (tmp < val && j >= 0)
		{
			tmp = arr[++i][j];
		}
		else if (tmp > val && j >= 0)
		{
			tmp = arr[i][--j];
		}
		else
		{
			return 0;
		}
	}
}
int main()
{
	int a[ROW][COL] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16 };
	int i = 0;
	int j = 0;
	int num;
	for (i = 0; i < ROW; i++)
	{
		for (j = 0; j < COL; j++)
		{
			printf("%3d", a[i][j]);
		}
		printf("\n");
	}
	printf("������:");
	scanf("%d", &num);
	if (Yang(a, num))
	{
		printf("%d�ڸ�������\n", num);
	}
	else
	{
		printf("%d���ڸ�������\n", num);
	}
	return 0;
}
