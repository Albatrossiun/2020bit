#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>

//��д������һ�� 1�� 100 �����������г��ֶ��ٸ�����9
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


//��ӡ����
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

//��ӡ����
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


//���������������������������Լ��
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


//дһ���������������Ľϴ�ֵ
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


//����:�Ȳ����� 2��5��8��11��14��������
//���� : ������N > 0
//���:��Ȳ�����ǰN���
//���� : ת���ɹ����� 0, �Ƿ��������쳣���� - 1
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


//����һ��������������������ַ�������ʽ�������
//���򲻿��Ǹ���������������ֺ���0����������ʽҲ����0��������Ϊ100�������Ϊ001
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


//����һ��������������������ַ�������ʽ�������
//���򲻿��Ǹ���������������ֺ���0����������ʽҲ����0��������Ϊ100�������Ϊ001
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


//д��һ�����򣬽���һ����������ֵ���������ֵ�Ľ�������ֵ��
//���С�������ֵ���ڵ���5,����ȡ����С��5��������ȡ����
//int main()
//{
//    float tmp;
//    while (1)
//    {
//        printf("������һ������������");
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