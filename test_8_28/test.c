#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>

//void print_arr(int arr[3][4], int row, int col)
//{
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < row; i++)
//	{
//		for (j = 0; j < col; j++)
//		{
//			printf("%d ", arr[i][j]);
//		}
//		printf("\n");
//	}
//}
//
//int main()
//{
//	int arr[3][4] = {1,2,3,4,5,6,7,8,9};
//	print_arr(arr, 3, 4);
//	return 0;
//}

//int main()
//{
//	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	//���󲿷�����£�����������Ԫ�صĵ�ַ
//	//��2�����⣺
//	//sizeof(������) - �������Ǳ�ʾ�������飬sizeof(������)���������������Ĵ�С
//	//&������  - ��������ʾ�������飬&������ ȡ������ ��������ĵ�ַ
//
//	printf("%p\n", arr);
//	printf("%d\n", *arr);
//
//	printf("%p\n", &arr[0]); 
//
//	return 0;
//}
//
//�����ʾ��
////�β�arr������Ӧ����һ��ָ��
//void bubble_sort(int arr[])
//{
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int i = 0;
//	//ð�����������
//	for (i = 0; i < sz - 1; i++)
//	{
//		//һ��ð������
//		int j = 0;
//		for (j = 0; j < sz-1-i; j++)
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
//
//void bubble_sort(int arr[], int sz)
//{
//	int i = 0;
//	//ð�����������
//	for (i = 0; i < sz - 1; i++)
//	{
//		//һ��ð������
//		int j = 0;
//		for (j = 0; j < sz - 1 - i; j++)
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
//int main()
//{
//	int arr[] = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//
//	//����-�ų�����
//	//arr������
//	//���ִ��ε�ʱ���������ᷢ������
//	//���������������������Ԫ�صĵ�ַ
//	//���鴫��ʵ���ϴ�����������Ԫ�صĵ�ַ
//	print_arr(arr, sz);
//
//	bubble_sort(arr, sz);//ð������ķ�ʽ
//
//	print_arr(arr, sz);
//	return 0;
//}

//
//int main()
//{
//	int arr1[3][4] = { { 1, 2 }, { 3, 4 }, { 5 } };
//	int*p = &arr1[0][0];
//	int i = 0;
//	for (i = 0; i < 12; i++)
//	{
//		printf("%d ", *p);
//		p++;
//	}
//
//	return 0;
//}
//


//int main()
//{
//	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	int*p = arr;//��������������Ԫ�صĵ�ַ
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", *p);
//		p++;
//	}
//	return 0;
//}

//int main()
//{
//	int arr1[3][4] = { { 1, 2 }, { 3, 4 }, { 5 } };
//	int i = 0;//����
//	int j = 0;//����
//	for (i = 0; i < 3; i++)
//	{
//		for (j = 0; j < 4; j++)
//		{
//			printf("&arr[%d][%d] = %p\n", i, j, &arr1[i][j]);
//		}
//	}
//
//	return 0;
//}

//int main()
//{
//	//int arr1[3][4] = {1,2,3,4,5};
//	//��ά���֣���ʱ�������ʼ���ˣ���������ʡ�ԣ����������ǲ���ʡ�Ե�
//	int arr1[3][4] = { { 1, 2 }, { 3, 4 }, { 5 } };
//	int i = 0;//����
//	int j = 0;//����
//	for (i = 0; i < 3; i++)
//	{
//		for (j = 0; j < 4; j++)
//		{
//			printf("%d ", arr1[i][j]);
//		}
//		printf("\n");
//	}
//
//	//double arr2[3][5];
//
//	return 0;
//}
//
//int main()
//{
//	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
//	//0 1 2 3 4 ...
//	int i = 0;
//	//����һ�������Ԫ�ظ���
//	int sz = sizeof(arr) / sizeof(arr[0]);
//
//	for (i = 0; i < sz; i++)
//	{
//		printf("%p\n", &arr[i]);
//	}
//
//	return 0;
//}



//int main()
//{
//	int arr[] = { 1, 2, 3, 4, 5, 6, 7 ,8, 9};
//	//0 1 2 3 4 ...
//	int i = 0;
//	//����һ�������Ԫ�ظ���
//	int sz = sizeof(arr) / sizeof(arr[0]);
//
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//
//	return 0;
//}

//
//int main()
//{
//	//����ȫ��ʼ����ʣ���Ԫ��Ĭ�ϳ�ʼ��Ϊ0
//	//int array[10] = {1,2,3};//��������ʼ��
//	//int arr2[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	//int arr3[10] = { 0 };
//	//int arr4[] = { 1, 2, 3, 4, 5 };
//	//int arr5[];//err
//	char ch1[] = { 'a', 'b', 'c', 'd' };
//	char ch2[] = "abcd";
//	printf("%d\n", sizeof(ch1));//
//	printf("%d\n", sizeof(ch2));//
//	printf("%d\n", strlen(ch1));//
//	printf("%d\n", strlen(ch2));//
//
//	//char ch[7];
//	
//	//int n = 10;
//	//int arr1[n] = {0};//err
//
//	return 0;
//}