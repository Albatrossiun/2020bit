#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

//int main()
//{
//	char ch = 'w';
//	char* pc = &ch;
//
//	//����д���ǲ��Ͻ���-gcc
//	char* ps = "hello bit";//�����ַ���
//
//	//�Ͻ���д��
//	const char* ps2 = "hello bit";
//
//	char arr[] = "hello bit";
//	return 0;
//}

//
//ָ������ - ����
//���ָ��(��ַ)������
//
//int main()
//{
//	//int a = 10;
//	//int b = 20;
//	//int c = 30;
//
//	////arr����ָ������
//	//int* arr[3] = { &a, &b, &c };//int*
//
//	int arr1[] = { 1, 2, 3, 4 };
//	int arr2[] = { 2, 3, 4, 5 };
//	int arr3[] = { 3, 4, 5, 6 };
//
//	int* arr4[] = { arr1, arr2, arr3 };
//
//	int i = 0;
//	for (i = 0; i < 3; i++)
//	{
//		int j = 0;
//		for (j = 0; j < 4; j++)
//		{
//			printf("%d ", arr4[i][j]);
//		}
//		printf("\n");
//	}
//
//	return 0;
//}


//
//����ָ��-ָ��
//ָ�������ָ��
//
//int*p; p��һ��ָ�����ε�ָ��
//char* pc;//pc��һ��ָ���ַ���ָ��

//int main()
//{
//	int a = 10;
//	int* p = &a;
//
//	int arr[5] = { 1, 2, 3, 4, 5 };//5*4 = 20
//	int(* pa)[5] = &arr;//&arr�õ���������ĵ�ַ
//
//	//pa����һ������ָ�룬��ָ��ָ��һ�����飬������5��Ԫ�أ�ÿ��Ԫ�ص�������int
//	//����ĵ�ַ�ͷ�������ָ�����ȥ
//
//	return 0;
//}

//����ָ���ʹ��
//
//int main()
//{
//	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	//1
//	int* p = arr;
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", *(p + i));
//	}
//
//	//2
//	//int(*p)[10] = &arr;
//
//	//int i = 0;
//	//for (i = 0; i < 10; i++)
//	//{
//	//	printf("%d ", (*p)[i]);
//	//}
//
//	return 0;
//}

//void print(int arr[], int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//}

//void print(int* arr, int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		//printf("%d ", arr[i]);//1 - �������Լ�Ҳ���arr[i]ת����*(arr+i)
//		printf("%d ", *(arr + i));//2
//	}
//}

//int main()
//{
//	int arr2[] = { 1, 2, 3, 4, 5, 6 };
//	print(arr2, 6);
//	return 0;
//}
//
//void print1(int arr[3][5], int x, int y)
//{
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < x; i++)
//	{
//		for (j = 0; j < y; j++)
//		{
//			printf("%d ", arr[i][j]);
//		}
//		printf("\n");
//	}
//}
//
////����ָ��
//void print2(int(*p)[5], int x, int y)
//{
//	int i = 0;
//	for (i = 0; i < 3; i++)
//	{
//		int j = 0;
//		for (j = 0; j < 5; j++)
//		{
//			printf("%d ", (*(p + i))[j]);
//		}
//		printf("\n");
//	}
//}
//
//
//void print3( int(*p)[3][5] )
//{
//
//}
//
////����ָ���ʹ�ã�һ�鳣���ڶ�ά����
//int main()
//{
//	int arr[3][5] = { { 1, 2, 3, 4, 5 }, { 2, 3, 4, 5, 6 }, { 3, 4, 5, 6, 7 } };
//
//	//дһ��������ӡarr���������
//	//print1(arr, 3, 5);//�����arrҲ������������ʾ����Ȼ����Ԫ�صĵ�ַ
//	print2(arr, 3, 5);
//	print3(&arr);
//	return 0;
//}

//void test(int arr[][5])
//{
//
//}
//
//int main()
//{
//	int arr[][5] = { 1, 2, 3, 4, 5, 6 };
//	test(arr);
//	return 0;
//}

//
//void test1(int* p)
//{
//}
//
//void test2(char* p)
//{}
//
//int main()
//{
//	char ch = 'w';
//	char* pc = &ch;
//	char arr2[5];//
//	test2(arr2);
//
//	test2(&ch);
//	test2(pc);
//
//	int a = 10;
//	int* ptr = &a;
//	int arr[10];
//	test1(&a);//ok
//	test1(ptr);//ok
//	test1(arr);//ok
//
//	return 0;
//}
//
//void test(int** p)
//{}
//
//int main()
//{
//	int* p1;
//	int **ptr;
//	int* arr[5];//
//	test(ptr);
//	test(&p1);
//	test(arr);
//	
//	return 0;
//}


int my_strlen(const char* str)
{
	return 0;
}

int Add(int x, int y)
{
	return x + y;
}



int main()
{
	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8 };
	int(*p)[10] = &arr;//ȡ������ĵ�ַ p��������ָ��

	//����ָ�������
	//��һ��ָ������ָ�� - ��ź����ĵ�ַ
	//int (*pf)(int, int) = &Add;
	int(*pf)(int, int) = Add;
	int sum = (*pf)(2, 3);
	sum = pf(2, 3);

	printf("%d\n", sum);
	//sum = Add(2, 3);
	printf("%d\n", sum);


	//int (*ps)(const char*) = &my_strlen;

	//printf("%p\n", &Add);
	//printf("%p\n", Add);
	//�������Ǻ����ĵ�ַ
	//&���������Ǻ����ĵ�ַ

	return 0;
}