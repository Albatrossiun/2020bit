#define _CRT_SECURE_NO_WARNINGS 1

#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int main()
{
	int a = 10;
	int arr[10] = { 0 };
	printf("%d\n", sizeof(arr));//����������ܴ�С����λ���ֽ�
	printf("%d\n", sizeof(int[10]));

	//printf("%d\n", sizeof(a));
	//printf("%d\n", sizeof(int));

	return 0;
}

//int main()
//{
//	int a = 10;//4���ֽڵĿռ�
//	int* pa = &a;//ָ�����
//	*pa = 20;//* �����ò�����
//
//	printf("a = %d\n", a);
//	return 0;
//}


//int main()
//{
//	int a = -10;
//	a = -a;
//
//	return 0;
//}

//
//int main()
//{
//	//3 + 5;//+ ��2�������� ˫Ŀ������
//	//��Ŀ������-ֻ��һ���������Ĳ�����
//	//int a = 10;
//	//printf("%d\n", a);//10-����-��
//	//printf("%d\n", !a);//0
//	int flag = 1;
//	if (!flag)
//	{
//		
//	}
//	return 0;
//}
//
//int main()
//{
//	int a = 0;
//	a = a + 3;	//1
//	a += 3;		//2-������
//
//	a = a - 10;
//	a -= 10;
//
//	a = a >> 1;
//	a >>= 1;
//
//	a = a & 5;
//	a &= 5;
//
//	//a = 3;//��ֵ������
//
//	//== �ж��Ƿ����
//
//	return 0;
//}

//��һ�������洢���ڴ��еĶ�������1�ĸ���
//int a = 6;
//00000000000000000000000000000110
//123
//123%10
//123/10 = 12
//%10 /10
//
//110
//1
//���ֽⷨ������-err
//int count_one(int n)
//{
//	int count = 0;
//	while (n)
//	{
//		if (n % 2 == 1)
//		{
//			count++;
//		}
//		n = n / 2;
//	}
//	return count;
//}
//google - 
//int count_one(int n)
//{
//	int count = 0;
//	int i = 0;
//	for (i = 0; i < 32; i++)
//	{
//		if ( ( (n >> i) & 1) == 1 )
//		{
//			count++;
//		}
//	}
//	return count;
//}
//n=7
//n = n&(n-1)
//111-n
//110
//110-n
//101
//100-n
//011
//000-n
//
//int count_one(int n)
//{
//	int count = 0;
//	while (n)
//	{
//		n = n&(n - 1);
//		count++;
//	}
//	return count;
//}
//
//int main()
//{
//	int a = -1;
//	//11111111111111111111111111111111
//	//00000000000000000000000000000001
//	//00000000000000000000000000000001
//	//
//	int ret = count_one(a);
//	printf("%d\n", ret);
//	return 0;
//}
//


//int main()
//{
//	int a = 3;
//	int b = 5;
//	printf("a=%d b=%d\n", a, b);
//
//	a = a^b;
//	b = a^b;
//	a = a^b;
//
//	printf("a=%d b=%d\n", a, b);
//
//	return 0;
//}



//int main()
//{
//	int a = 3;
//	int b = 5;
//	int c = 0;//ʹ������ʱ����
//	printf("a=%d b=%d\n", a, b);
//	c = a;
//	a = b;
//	b = c;
//	printf("a=%d b=%d\n", a, b);
//
//	return 0;
//}

//��λ������
//>> 
//<<

//int main()
//{
//	int a = 3;
//	int b = 5;
//	int c = a ^ b;//|-����2���ƣ�λ���
//	//011
//	//101
//	//110
//	printf("c = %d\n", c);
//
//	return 0;
//}

//int main()
//{
//	int a = 3;
//	int b = 5;
//	int c = a|b;//|-����2���ƣ�λ��
//	//011
//	//101
//	//
//	printf("c = %d\n", c);
//
//	return 0;
//}

//int main()
//{
//	int a = 3;
//	int b = 5;
//	int c = a&b;//&-����2���ƣ�λ��
//	//011
//	//101
//	//001
//	//
//	printf("c = %d\n", c);
//
//	return 0;
//}
//int main()
//{
//	int a = -1;
//	int b = a >> 1;
//	printf("b = %d\n", b);
//
//	//a��һ��int�ı���
//	//4���ֽ�
//	//4*8bitλ
//	//32bit
//	//11111111111111111111111111111111
//	//
//	return 0;
//}



//
//int main()
//{
//	int a = 7;
//	int b = a >> 1;
//	printf("b = %d\n", b);
//
//	//a��һ��int�ı���
//	//4���ֽ�
//	//4*8bitλ
//	//32bit
//	//00000000000000000000000000000111
//	//
//	//a >> 1;
//	//a << 1;
//	//���Ʋ�����-�ƶ����Ƕ�����λ
//	//111;
//	return 0;
//}


//int main()
//{
//	int a = 7;
//	int b = a << 1;
//	printf("b = %d\n", b);
//	//a��һ��int�ı���
//	//4���ֽ�
//	//4*8bitλ
//	//32bit
//	//00000000000000000000000000000111
//	//
//	//a >> 1;
//	//a << 1;
//	//���Ʋ�����-�ƶ����Ƕ�����λ
//	//111;
//	return 0;
//}

//int main()
//{
//	//6.0%2.0;//err
//	//6 % 2;
//	double a = 7 / 2.0;
//	printf("a = %lf\n", a);
//
//	return 0;
//}