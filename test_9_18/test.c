#define _CRT_SECURE_NO_WARNINGS 1
#include <string.h>
#include <stdio.h>

//��-������һ���ṹ������
//int float
//struct Book
//{
//	char name[20];//����
//	short price;  //����
//}b4,b5,b6;//ȫ�ֱ���
//
//typedef struct Book
//{
//	char name[20];//����
//	short price;  //����
//}Book;
//
//int main()
//{
//	//���ýṹ�����ʹ����ṹ�����-�ֲ�����
//	struct Book b1;//����һ����
//	struct Book b2;//����һ����
//	struct Book b3;//����һ����
//	Book b4;
//	Book b5;
//
//	//�ַ�������
//	//�ѡ�C���ԡ�������name������
//
//	strcpy(b1.name, "C����");
//	b1.price = 55;
//	
//	printf("%s\n", b1.name);
//	printf("%d\n", b1.price);
//
//	return 0;
//}

struct B
{
	int a;
	char c;
};

//struct S
//{
//	int a;//����
//	char arr[20];//����
//	int*p;//ָ��
//	struct B sb;//�ṹ��
//};
//
//int main()
//{
//	int a = 0;//��ʼ��
//
//	struct B b = {20, 'w'};
//	struct S s = { 100, "hehe", NULL, {33, 'Q'} };
//	printf("%d %s %d %c\n", s.a, s.arr, s.sb.a, s.sb.c);
//
//	return 0;
//}
//
//struct Stu
//{
//	char name[20];//20
//	int age;//4
//};
//
//void print1(struct Stu stu)
//{
//	printf("%s %d\n", stu.name, stu.age);
//}
//
//void print2(struct Stu* ps)
//{
//	//printf("%s %d\n", (*ps).name, (*ps).age);
//	printf("%s %d\n", ps->name, ps->age);
//}
//
//int main()
//{
//	struct Stu s = {"����", 20};
//	//��ֵ����
//	print1(s);
//
//	//��ַ����
//	print2(&s);
//
//	return 0;
//}


int Add(int c, int d)
{
	int z = 0;
	z = c + d;
	return z;
}

int main()
{
	int a = 10;
	int b = 20;
	int c = Add(a, b);

	return 0;
}