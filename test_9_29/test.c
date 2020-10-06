#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>

//编写程序数一下 1到 100 的所有整数中出现多少个数字9
int main()
{
	int i = 0;
	int count = 0;
	for (i = 1; i <= 100; i++)
	{
		if (i % 10 == 9)
			count++;
		if (i / 10 == 9)
			count++;
	}
	printf("%d\n", count);
	return 0;
}


//打印素数
//int main()
//{
//	int i = 0;
//	int count = 0;
//	for (i = 101; i <= 200; i++)
//	{
//		int j = 0;
//		for (j = 2; j < i; j++)
//		{
//			if (i % j == 0)
//			{
//				break;
//			}
//		}
//		if (j == i)
//		{
//			count++;
//			printf("%d ", i);
//		}
//	}
//	printf("\ncount = %d\n", count);
//	return 0;
//}

//打印闰年
//int main()
//{
//	int year = 0;
//	for (year = 1000; year <= 2000; year++)
//	{
//		if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
//		{
//			printf("%d ", year);
//		}
//	}
//
//	return 0;
//}


//给定两个数，求这两个数的最大公约数
//int main()
//{
//	int a, b;
//	scanf("%d %d", &a, &b);
//	int tmp;
//	while (b)
//	{
//		tmp = a % b;
//		a = b;
//		b = tmp;
//	}
//	printf("%d\n", a);
//	return 0;
//}


//写一个函数求两个数的较大值
//int compare(int a,int b)
//{
//	if (a >= b)
//		return a;
//	else
//		return b;
//}
//int main()
//{
//	int a, b;
//	scanf("%d %d", &a, &b);
//	printf("%d\n",compare(a, b));
//	return 0;
//}


//功能:等差数列 2，5，8，11，14。。。。
//输入 : 正整数N > 0
//输出:求等差数列前N项和
//返回 : 转换成功返回 0, 非法输入与异常返回 - 1
//int main()
//{
//	int num;
//	int sum = 2;
//	int count = 0;
//	while (1)
//	{
//		scanf("%d", &num);
//		if (num > 0)
//			break;
//	}
//	for (num; num > 1; num--)
//	{
//		sum = sum + 3;
//		count = count + sum;
//	}
//	printf("%d\n", count + 2);
//}


//输入一个整数，将这个整数以字符串的形式逆序输出
//程序不考虑负数的情况，若数字含有0，则逆序形式也含有0，如输入为100，则输出为001
//int main()
//{
//	char tmp[20];
//	scanf("%s", tmp);
//	int size = strlen(tmp);
//	int left = 0;
//	int right = size - 1;
//	while (left <= right)
//	{
//		char a;
//		a = tmp[left];
//		tmp[left] = tmp[right];
//		tmp[right] = a;
//		left++;
//		right--;
//	}
//	printf("%s\n", tmp);
//}


//输入一个整数，将这个整数以字符串的形式逆序输出
//程序不考虑负数的情况，若数字含有0，则逆序形式也含有0，如输入为100，则输出为001
//int main()
//{
//	char string[20] = { '\0' };
//	scanf("%s", string);
//	for (int i = strlen(string) - 1; i >= 0; i--)
//	{
//		printf("%c", string[i]);
//	}
//	printf("\n");
//	return 0;
//}


//写出一个程序，接受一个正浮点数值，输出该数值的近似整数值。
//如果小数点后数值大于等于5,向上取整；小于5，则向下取整。
//int main()
//{
//    float tmp;
//    while (1)
//    {
//        printf("请输入一个正浮点数：");
//        scanf("%f", &tmp);
//        if (tmp > 0.0)
//        {
//            break;
//        }
//    }
//    float a;
//    a = tmp; // a=5.6
//    tmp = tmp * 10.0; // tmp=56
//    tmp = (int)tmp % 10;  // tmp =5
//    if (tmp >= 5)
//    {
//        a = (int)a + 1;
//    }
//    else
//    {
//        a = (int)a;
//    }
//    printf("%d", (int)a);
//}