#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>


//int main()
//{
//	int i = 1;
//	while (i <= 100)
//	{
//		printf("%d ", i);
//		i+=2;
//	}
//
//	return 0;
//}

//int main()
//{
//	int i = 1;
//	while (i <= 100)
//	{
//		if (i % 2 == 1)
//		{
//			printf("%d ", i);
//		}
//		i++;
//	}
//
//	return 0;
//}

//int main()
//{
//	int num = 0;
//	scanf("%d", &num);
//	if (num % 2 == 1)
//	{
//		printf("����\n");
//	}
//	else
//	{
//		printf("��������\n");
//	}
//
//	return 0;
//}

//
//int main()
//{
//	int a = 10;
//	if (4 == a)
//	{
//		printf("a == 4\n");
//	}
//	//if (a = 4)//bug
//	//{
//	//	printf("a == 4\n");
//	//}
//
//	return 0;
//}

//
//#include <stdio.h>
//int main()
//{
//	int a = 0;
//	int b = 2;
//
//	if (a == 1)
//	{
//		if (b == 2)
//			printf("hehe\n");
//	}
//	else
//		printf("haha\n");
//
//	return 0;
//}


//
//int main()
//{
//	int age = 10;
//	
//	if (age < 16)
//	{
//		printf("����\n");
//		printf("����̸����\n");
//	}
//	else if (age >= 16 && age < 30)
//		printf("����\n");
//	else if (age >= 30 && age < 50)
//		printf("׳��\n");
//	else if (age >= 50 && age < 90)
//		printf("����\n");
//	else
//		printf("�ϲ���\n");
//
//	return 0;
//}

//int main()
//{
//	//int age = 20;
//	//if (age < 18)
//	//	printf("δ����\n");
//
//
//	int age = 10;
//	if (age < 18)
//		printf("δ����\n");
//	else
//		printf("����\n");
//
//	return 0;
//}

//int main()
//{
//	int a = 10;
//	10;
//	;//�����
//	return 0;
//}

//�ṹ��ؼ���

//ѧ������
//struct Stu
//{
//	char name[200];//����
//	short age;//����
//};
//
////.   �ṹ�����.�ṹ��ĳ�Ա
////->  �ṹ��ָ��->�ṹ��ĳ�Ա
//
//int main()
//{
//	//char arr[] = "hello";
//	struct Stu s1 = {"����", 30};//s��ѧ���ı���
//	struct Stu * ps = &s1;
//	//s1.name
//	printf("%s %d\n", (*ps).name, (*ps).age);
//
//	//printf("%s %d\n", ps->name, ps->age);
//
//	//printf("%s %d\n", s1.name, s1.age);
//
//	//struct Stu s2;//s��ѧ���ı���
//
//	return 0;
//}

//ָ��

//int main()
//{
//	char ch = 'b';
//	char* pc = &ch;
//	*pc = 'w';
//	printf("%c\n", ch);
//
//	//int a = 10;
//	//int* pa = &a;
//	//*pa = 0;//* - �����ò�����
//	//
//	//printf("%d\n", a);//10 -11?
//
//	return 0;
//}

//int main()
//{
//	int a = 100;//��������a��Ҫ���ڴ�����4���ֽڵĿռ�
//	int * p = &a;//& ȡ��ַ������ p����һ��ָ�����
//
//	char ch = 'w';
//	char * pc = &ch;
//
//	//�ڴ��ӵ�����ʲô���Ƕ���
//	//��ָ������ʲô���ǵ�ַ
//
//	//%p - ��ӡ��ַ - 16���Ƶ�
//	//printf("%p\n", &a);
//
//	return 0;
//}
//#define������ų���
//#define MAX 100

//#define �����
//�ӷ��ĺ�
//#define ADD(X, Y) ((X)+(Y))
//
//
//int main()
//{
//	//int a = MAX;
//	//printf("%d\n", a);//100
//	int sum = ADD(3,5);
//	printf("sum = %d\n", sum);
//
//	return 0;
//}

//����һ�º���
//extern int Add(int x, int y);
//
//int main()
//{
//	int a = 10;
//	int b = 20;
//
//	int ret = Add(a, b);
//
//	printf("%d\n", ret);
//
//	return 0;
//}

////�����ⲿ����
//extern int g_val;
//
//int main()
//{
//	printf("%d\n", g_val);
//	return 0;
//}

//1. static���ξֲ�����

//void test()
//{
//	//static���ξֲ�����
//	static int i = 1;
//	i++;
//	printf("%d ", i);
//}
//
//int main()
//{
//	int  i = 0;
//	//ѭ��10��
//	while (i < 10)
//	{
//		test(); 
//		i++;
//	}
//	return 0;
//}


//int main()
//{
//	int i=12;
//	int tmp;
//	for (i = 1;i<101;i++)
//	{
//		tmp = i % 10;
//		if ((tmp + i) % 3 == 0)
//			printf("%d\n", i);
//	}
//	return 0;
//}


//int main()
//{
//	int i;
//	int a, b, c;
//	int j;
//	int r = 0;
//	scanf("%d %d %d",&a,&b,&c);
//	int t[] = { a,b,c };
//	for (i = 0; i<2; i++)
//		for (j = 0; j<2-i; j++)
//		{
//			if (t[j] < t[j + 1])
//			{
//				r = t[j];
//				t[j] = t[j + 1];
//				t[j + 1] = r;
//			}
//		}
//	for (i = 0; i<3; i ++)
//	{
//		printf("%d\n", t[i]);
//	}
//	return 0;
//}

//int main()
//{
//	int i = 1;
//	for (i = 1; i<=100; i ++)
//	{
//		if (i % 2 == 1)
//		{
//			printf("%d\n",i);
//		}
//	}
//	return 0;
//}