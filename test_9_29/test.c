#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>

//����:�Ȳ����� 2��5��8��11��14��������
//���� : ������N > 0
//���:��Ȳ�����ǰN���
//���� : ת���ɹ����� 0, �Ƿ��������쳣���� - 1
int main()
{
	int num;
	int sum = 2;
	int count = 0;
	while (1)
	{
		scanf("%d", &num);
		if (num > 0)
			break;
	}
	for (num; num > 1; num--)
	{
		sum = sum + 3;
		count = count + sum;
	}
	printf("%d\n", count + 2);
}


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