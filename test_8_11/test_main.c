#define _CRT_SECURE_NO_WARNINGS 1


#include <stdio.h>
#include <string.h>

//�����ⲿ����
extern int Add(int x, int y);

int main()
{
	int a = 10;
	int b = 20;
	int sum = Add(a, b);
	printf("sum = %d\n", sum);

	return 0;
}
//extern int g_val;
//
//int main()
//{
//	printf("%d\n", g_val);
//
//	return 0;
//}
//
//void test()
//{
//	static int a = 1;
//	a++;
//	printf("%d ", a);
//}
//
//int main()
//{
//	int i = 0;
//
//	//ѭ��ִ��10��
//	while (i<10)
//	{
//		test();
//		i++;
//	}
//
//	return 0;
//}

//���ܹؼ���
//���ߴ�� - �Լ������ı����������ǹؼ���
//int main()
//{
//	int typedef;
//	return 0;
//}


//����
//С��
//
//typedef unsigned int uint;
////��
////��ʿ
//
//int main()
//{
//	unsigned int num = 10;
//	uint num2 = 20;
//	return 0;
//}
////
//int main()
//{
//	register int a = 10;//�����a���ڼĴ�����ȥ
//	//������
//	return 0;
//}
//ȫ�ֱ����������� - ��������

//ʹ��extern ����һ�������ⲿ�ķ���
//extern int g_val;
//
//int main()
//{
//	printf("g_val = %d\n", g_val);
//
//	return 0;
//}

//int main()
//{
//	{
//		auto int a = 10;//ͨ����autoʡ��
//	}
//
//	return 0;
//}
//
//int main()
//{
//	printf("hello bit\n");//�������ò�����
//
//	return 0;
//}

//int main()
//{
//	int arr[10] = { 1, 2, 3, 4, 5 };
//
//	arr[4] = 6;//[]�����±����ò�����
//
//	return 0;
//}

//int main()
//{
//	//���ű��ʽ�����������μ��㣬�����������ʽ�Ľ�������һ�����ʽ�Ľ��
//
//	int a = (3+1,5+2,8+1,2-4);
//
//	printf("%d\n", a);//-2
//
//	return 0;
//}

//
//int main()
//{
//	int a = 10;
//	int b = 20;
//	int max = 0;
//
//	/*if (a > b)
//	{
//		max = a;
//	}
//	else
//	{
//		max = b;
//	}*/
//
//	max = (a > b ? a : b);
//	printf("max = %d\n", max);
//
//	return 0;
//}

//int main()
//{
//	int a = 0;
//	int b = 0;
//	//int c = a && b;//�߼���
//	int c = a || b;//�߼���
//
//	printf("c = %d\n", c);
//
//	return 0;
//}

//int main()
//{
//	int a = 4;
//	if (a == 3)
//	{
//		printf("hehe\n");
//	}
//
//	return 0;
//}

//int main()
//{
//	int a = (int)3.14;
//	printf("a = %d\n", a);
//	return 0;
//}

//
//int main()
//{
//	int a = 10;
//	int b = a--;
//
//	printf("a=%d b=%d\n", a, b);//9 10
//
//	/*int b = --a;
//	printf("a=%d b=%d\n", a, b);*/
//
//	//int b = ++a;//ǰ��++���ȸ�a��ֵ+1����ʹ��
//	//printf("a = %d b = %d\n", a, b);//a=11 b=11
//
//	//int b = a++;//����++����ʹ��a��ֵ������a��1
//	//printf("a = %d b = %d\n", a, b);//a=11 b=10
//
//	return 0;
//}


//int main()
//{
//	int a = 0;
//	//
//	//00000000000000000000000000000000
//	//11111111111111111111111111111111 - ����
//	//11111111111111111111111111111110 - ����
//	//10000000000000000000000000000001 - ԭ��
//	printf("%d\n", ~a);//-1
//	return 0;
//}

//int main()
//{
//	int a = -1;
//	//��ʮ���Ƶ����ֿ���ת���ɶ�����
//	//�����������ֱ�ʾ��ʽ��ԭ�롢���롢����
//	//������λ�����Ϊ�Ƿ���λ
//	//���λ��1����ʾ����
//	//���λ��0����ʾ����
//	//10000000000000000000000000000001 - ԭ��
//	//11111111111111111111111111111110 - ����
//	//11111111111111111111111111111111 - ����
//	//
//	//�������ڴ��д洢���Ƕ����Ʊ�ʾ�Ĳ���
//	//
//	//��������ԭ�롢���롢������ͬ
//	//
//	return 0;
//}
//int main()
//{
//	int a = 10;
//	char c = 'w';
//
//	//sizeof ��һ��������
//	//sizeof ������Ǳ�����ռ�ڴ�ռ�Ĵ�С
//	
//	printf("%d\n", sizeof(a));//
//	printf("%d\n", sizeof(int));//
//
//	printf("%d\n", sizeof(c));//
//	printf("%d\n", sizeof(char));//
//
//	return 0;
//}
//C�������������ͼٵ��أ�
//0 - ��ʾ��
//��0 - ��ʾ��
//

//int main()
//{
//	int a = -10;
//	int b = a;
//	printf("%d\n", b);
//
//	//int a = 10;//
//	//int b = 0;
//	//printf("%d\n", a);//10
//	//printf("%d\n", !a);//0
//	//printf("%d\n", b);//0
//	//printf("%d\n", !b);//1
//
//	return 0;
//}
//
//int main()
//{
//	int a = 10;
//	//a = a + 5;//1
//	//a += 5;   //2
//	//a = a - 3;
//	//a -= 3;
//	a = a >> 1;//1
//	a >>= 1;//2
//	printf("a = %d\n", a);
//
//	return 0;
//}

//
//int main()
//{
//	//&
//	int a = 3;
//	int b = 5;
//
//	int c = a^b;//���������ƣ�λ���
//	//00000000000000000000000000000011
//	//00000000000000000000000000000101
//	//00000000000000000000000000000110
//	//6
//
//	//int c = a | b;//���������ƣ�λ��
//	//00000000000000000000000000000011
//	//00000000000000000000000000000101
//	//00000000000000000000000000000111
//	//7
//
//	//int c = a&b;//���������ƣ�λ��
//	//00000000000000000000000000000011
//	//00000000000000000000000000000101
//	//00000000000000000000000000000001 - 1
//	//
//	printf("%d\n", c);
//
//	return 0;
//}
//
//int main()
//{
//	//������4���ֽڵ� - 32bitλ
//	int a = 8;
//	//�������ƶ�����a�Ķ�����λ
//	int b = a >> 1;//��a��ֵ�����ƶ�һλ
//	printf("%d\n", b);
//
//	//8 - 10����
//	//00000000000000000000000000001000
//
//
//
//	return 0;
//}

//int main()
//{
//	printf("%d\n", 7 / 2);//��
//	printf("%d\n", 7 % 2);//% - ȡģ - ȡģ�õ���������
//
//	return 0;
//}

//%d
//%c
//%s
//%f - ��ӡС����

//int main()
//{
//	printf("%f\n", 7 / 2.0);
//
//	return 0;
//}

//int main()
//{
//	int a = 10;
//	int b = 20;
//	a + b;
//	a - b;
//	a * b;
//	a / b;
//
//	return 0;
//}

//int main()
//{
//	//��ʼ������arr��ǰ5��Ԫ��Ϊ1,2,3,4,5��ʣ�µ�5��Ԫ��Ĭ�ϻᱻ��ʼ��Ϊ0
//	int arr[10] = {1,2,3,4,5,6,7,8,9,10};
//	//һ��һ��һ���Ĵ�ӡ��
//	int i = 0;
//	while (i < 10)
//	{
//		printf("%d ", arr[i]);
//		i++;
//	}
//	//printf("%d\n", arr[5]);
//	//printf("%d\n", arr[9]);
//
//
//	return 0;
//}


//����ͨ����
//A - ���õ�д��
//int get_max(int x, int y)
//{
//	if (x > y)
//	{
//		printf("�ϴ�ֵ�ǣ�%d\n", x);
//	}
//	else
//	{
//		printf("�ϴ�ֵ�ǣ�%d\n", y);
//	}
//	return 0;
//}

//����һ������-get_max

//��������
//int get_max(int x, int y);
//
//int main()
//{
//	int a = 0;
//	int b = 0;
//	scanf("%d%d", &a, &b);//10 20
//	int max = get_max(a, b);
//	printf("max = %d\n", max);
//
//	return 0;
//}
//
//int get_max(int x, int y)
//{
//	int z = 0;
//	if (x > y)
//	{
//		z = x;
//	}
//	else
//	{
//		z = y;
//	}
//	return z;
//}


//
//int main()
//{
//	printf("%d\n", strlen("c:\test\121"));//7
//	return 0;
//}


//
//#include <stdio.h>
//#include <string.h>

//int main()
//{
//	char arr[] = { 'b', 'i', 't' };
//	printf("%d\n", strlen(arr));
//	return 0;
//}



//int Add(int x, int y)
//{
//	int z = 0;
//	z = x + y;
//	return z;
//}
//
//int main()
//{
//	int a = 10;
//
//	return 0;
//}
//int num = 10;
//int main()
//{
//	int num = 1;
//
//	printf("num = %d\n", num);//1
//	return 0;
//}
//