#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>

//
//struct S
//{
//	char name[20];
//	int age;
//};
//
//void bubble_sort(int arr[], int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz - 1; i++)
//	{
//		int j = 0;
//		for (j = 0; j <sz-1-i; j++)
//		{
//			if (arr[j] > arr[j + 1])
//			{
//				int tmp = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = tmp;
//			}
//		}
//	}
//}
//
//int main()
//{
//	//����
//	int arr1[] = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
//	int sz = sizeof(arr1) / sizeof(arr1[0]);
//	bubble_sort(arr1, sz);
//
//	float arr2[] = { 2.0, 1.0, 3.0, 0 };
//	bubble_sort(arr2, );
//
//	return 0;
//}

//void qsort(void *base, 
//	       size_t num, 
//		   size_t width, 
//	       int (*compare)(const void *elem1, const void *elem2)
//		   );


//
//#include <stdlib.h>
//
//int cmp_int(const void* e1, const void* e2)
//{
//	return *(int*)e1 - *(int*)e2;
//}
//
//void print_arr(int arr[], int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//}
//
//
//
//void _Swap(char* buf1, char* buf2, int width)
//{
//	int i = 0;
//	for (i = 0; i < width; i++)
//	{
//		char tmp = *(buf1 + i);
//		*(buf1 + i) = *(buf2 + i);
//		*(buf2 + i) = tmp;
//	}
//}
//
//void bubble_sort(void*base, int sz, int width, 
//	             int(*cmp)(const void* e1, const void*e2))
//{
//	int i = 0;
//	for (i = 0; i < sz - 1; i++)
//	{
//		int j = 0;
//		for (j = 0; j <sz-1-i; j++)
//		{
//			if (cmp((char*)base+j*width, (char*)base+(j+1)*width)>0)
//			{
//				//����
//				_Swap((char*)base + j*width, (char*)base + (j + 1)*width, width);
//			}
//		}
//	}
//}
//
//
////qsort ��������
//void test1()
//{
//	int arr[] = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	print_arr(arr, sz);
//	//qsort(arr, sz, sizeof(arr[0]), cmp_int);
//	bubble_sort(arr, sz, sizeof(arr[0]), cmp_int);
//	print_arr(arr, sz);
//}
//
//struct S
//{
//	char name[20];
//	int age;
//};
//
//int cmp_stu_by_age(const void* e1, const void* e2)
//{
//	return (((struct S*)e1)->age - ((struct S*)e2)->age);
//}
//
////qsort ����ṹ������
//void test2()
//{
//	struct S arr[] = { { "zhangsan", 20 }, { "lisi", 80 }, { "wangwu", 5 } };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//
//	//qsort(arr, sz, sizeof(arr[0]), cmp_stu_by_age);
//	bubble_sort(arr, sz, sizeof(arr[0]), cmp_stu_by_age);
//}
//
//int cmp_stu_by_name(const void* e1, const void* e2)
//{
//	return strcmp(((struct S*)e1)->name, ((struct S*)e2)->name);
//}
//
//void test3()
//{
//	struct S arr[] = { { "zhangsan", 20 }, { "lisi", 80 }, { "wangwu", 5 } };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//
//	//qsort(arr, sz, sizeof(arr[0]), cmp_stu_by_name);
//	bubble_sort(arr, sz, sizeof(arr[0]), cmp_stu_by_name);
//}
//
//
//int main()
//{
//	test3();
//	return 0;
//}

//
//void* ��ָ�����޾������͵�ָ��
//���Խ��������������͵ĵ�ַ
//void* ��ָ�벻��ֱ��+- �����Ĳ���
//void* ��ָ�벻��ֱ�ӽ����ò���
//


//int main()
//{
//	int a = 10;
//	int* pa = &a;
//	char ch = 'w';
//	//char* pc = &a;//char*  != int*
//	void* pv = &a;
//	pv = &ch;
//
//	return 0;
//}
//123
//0x 11 22 33 44
//44 33 22 11
//��       ��

//
//int main()
//{
//	unsigned char a = 200;
//	unsigned char b = 100;
//	unsigned char c = 0;
//	c = a + b;
//	//00000000000000000000000011001000 - 200
//	//00000000000000000000000001100100 - 100
//
//	//00000000000000000000000011001000 - a
//	//00000000000000000000000001100100 - b
//	//00000000000000000000000100101100
//	//00000000000000000000000000101100 - c
//	//
//	printf("%d %d", a + b, c);// 300 44
//
//	return 0;
//}
//


//unsigned int a = 0x1234; 
//unsigned char b = *(unsigned char *)&a;


//��32λ���ģʽ�������ϱ���b���ڣ� ��


//�������
//��Ŀ���ݣ�
//����Ļ�ϴ�ӡ������ǡ�



//1
//1 1
//1 2 1
//1 3 3 1
//1 4 6 4 1
//
//int  main()
//{
//	int arr[100][100] = { 0 };
//	int i = 0;
//	int j = 0;
//	int n = 0;
//	scanf("%d", &n);
//	for (i = 0; i < n; i++)
//	{
//		for (j = 0; j < n; j++)
//		{
//			if (i == j)
//				arr[i][j] = 1;
//			if (j == 0)
//				arr[i][j] = 1;
//			if (i>=2 && j>=1)
//				arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
//		}
//	}
//
//	for (i = 0; i < n; i++)
//	{
//		for (j = 0; j <=i; j++)
//		{
//			printf("%d ", arr[i][j]);
//		}
//		printf("\n");
//	}
//	return 0;
//}
//
//
//

//�ձ�ĳ�ط�����һ��ıɱ��������ͨ���Ų�ȷ��ɱ�����ֱ�Ϊ4�����ɷ���һ����
//����Ϊ4�����ɷ��Ĺ��� :
//A˵�������ҡ�
//B˵����C��
//C˵����D��
//D˵��C�ں�˵
//��֪3����˵���滰��1����˵���Ǽٻ���

int main()
{
	int killer = 'a';
	for (killer = 'a'; killer <= 'd'; killer++)
	{
		if ((killer != 'a') + (killer == 'c') + 
			(killer == 'd') + (killer != 'd') == 3)
		{
			printf("%c\n", killer);
		}
	}
	return 0;
}


//5λ�˶�Ա�μ���10��̨��ˮ����������������Ԥ����������
//
//Aѡ��˵��B�ڶ����ҵ�����
//Bѡ��˵���ҵڶ���E���ģ�
//Cѡ��˵���ҵ�һ��D�ڶ���
//Dѡ��˵��C����ҵ�����
//Eѡ��˵���ҵ��ģ�A��һ��
//
//����������ÿλѡ�ֶ�˵����һ�룬����ȷ�����������Ρ�
//
//int main()
//{
//	int a = 0;
//	int b = 0;
//	int c = 0;
//	int d = 0;
//	int e = 0;
//	for (a = 1; a <= 5; a++)
//	{
//		for (b = 1; b <= 5; b++)
//		{
//			for (c = 1; c <= 5; c++)
//			{
//				for (d = 1; d <= 5; d++)
//				{
//					for (e = 1; e <= 5; e++)
//					{
//						if (((b == 2) + (a == 3) == 1) &&
//							((b == 2) + (e == 4) == 1) &&
//							((c == 1) + (d == 2) == 1) &&
//							((c == 5) + (d == 3) == 1) &&
//							((e == 4) + (a == 1) == 1))
//						{
//							if (a*b*c*d*e==120)
//							printf("a=%d b=%d c=%d d=%d e=%d\n", a, b, c, d, e);
//						}
//					}
//				}
//			}
//		}
//	}
//	return 0;
//}
//

//
//������
//
//����
//
//
//36ƥ��
//6�ܵ�
//
