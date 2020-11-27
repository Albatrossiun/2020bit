#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include <ctype.h>
#include <math.h>
#include <windows.h>
 
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int left = 0;
//	int right = sizeof(arr) / sizeof(arr[0]) - 1;
//	int key = 10;
//	int mid = 0;
//	while (left <= right)
//	{
//		mid = (left + right) / 2;
//		if (arr[mid] > key)
//		{
//			right = mid-1;  //  right = mid ;
//		}
//		else if (arr[mid] < key)
//		{
//			left = mid+1;	//   left = mid ;
//		}
//		else
//			break;
//	}
//	if (left <= right)
//		printf("找到了,下标是%d\n", mid);
//	else
//		printf("找不到\n");
//}

//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9 };
//	int size = sizeof(arr) / sizeof(arr[0]);
//	int left = 0;
//	int right = size - 1;
//	int mid = (left + right) / 2;
//	int num = 0;
//	int flag = 0;
//	scanf("%d", &num);
//	while (left <= right)
//	{
//		if (arr[mid] == num)
//		{
//			flag = 1;
//			printf("该数字位于第%d个\n", (mid + 1));
//			break;
//		}
//		else
//		{
//			if (arr[mid] > num)
//			{
//				right = mid - 1;
//				mid = (left + right) / 2;
//			}
//			else
//			{
//				left = mid + 1;
//				mid = (left + right) / 2;
//			}
//		}
//	}
//	if (flag == 0)
//	{
//		printf("数组中没有找到该数字！\n");
//	}
//	return 0;
//}

//int main()
//{
//	char psw[10] = "";
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < 3; ++i)
//	{
//		printf("please input:");
//		scanf("%s", psw);
//		if (strcmp(psw, "password") == 0)
//			break;
//	}
//	if (i == 3)
//		printf("exit\n");
//	else
//		printf("log in\n");
//}

//int main()
//{
//	char arr1[] = "welcome to bit...";
//	char arr2[] = "#################";
//	int left = 0;
//	int right = strlen(arr1) - 1;
//	printf("%s\n", arr2);
//	while循环实现
//	while (left <= right)
//	{
//		Sleep(1000);
//		arr2[left] = arr1[left];
//		arr2[right] = arr1[right];
//		left++;
//		right--;
//		printf("%s\n", arr2);
//	}
//	for循环实现
//	for (left = 0, right = strlen(arr2) - 1;
//		left <= right;
//		left++, right--)
//	{
//		Sleep(1000);
//		arr2[left] = arr1[left];
//		arr2[right] = arr1[right];
//		printf("%s\n", arr2);
//	}
//	return 0;
//}

//int main()
//{
//	int i = 0;
//	int k = 0;
//	for (i = 0, k = 0; k = 0; i++, k++)
//		k++;
//	return 0;
//}

//int main()
//{
//	int i = 1;
//	while (i <= 10)
//	{
//		if (i == 5)
//		{
//			i = i + 1;
//			continue;
//		}
//		printf("%d ", i); // 1 2 3 4
//		i = i + 1;
//	}
//	return 0; 
//}

//int main()
//{
//	int n = 1;
//	int m = 2;
//	switch (n)
//	{
//	case 1:
//		m++; // n=1 m=3
//	case 2:
//		n++; // n=2 m=3
//	case 3:
//		switch (n) // n=2 m=3
//		{//switch允许嵌套使用
//		case 1:
//			n++;
//		case 2: 
//			m++;
//			n++;
//			break;
//		}
//	case 4: // n=3 m=4
//		m++;
//		break;
//	default: // n=3 m=5
//		break;
//	}
//	printf("m = %d, n = %d\n", m, n);
//	return 0;
//}

//int main()
//{
//	printf("%c\n",65);
//	return 0;
//}

//int main()
//{
//	printf("%d\n", strlen("c:\test\328\test.c"));
//	return 0;
//}

//int main()
//{
//	问题1：在屏幕上打印一个单引号'，怎么做？
//	问题2：在屏幕上打印一个字符串，字符串的内容是一个双引号“，怎么做？
//	printf("%c\n", '\'');
//	printf("%s\n", "\"");
//	return 0;
//}

////下面代码，打印结果是什么？为什么？（突出'\0'的重要性）
//int main()
//{
//	char arr1[] = "bit";
//	char arr2[] = { 'b', 'i', 't' };
//	char arr3[] = { 'b', 'i', 't', '\0' };
//	printf("%s\n", arr1);
//	printf("%s\n", arr2);
//	printf("%s\n", arr3);
//	return 0;
//}


//void fun(char* arr, int length)
//{
//	int count = 0;
//	int i = 0;
//	for (i = 0; i < length; i++)
//	{
//		if (arr[i] == ' ')
//		{
//			count++;
//		}
//	}
//	int size = length + 2 * count - 1;
//	for (i = length-1 ; i >= 0; i--)
//	{
//		if (arr[i] == ' ')
//		{
//			arr[size--] = '0';
//			arr[size--] = '2';
//			arr[size--] = '%';
//		}
//		else
//		{
//			arr[size--] = arr[i];
//		}
//	}
//}
//
//int main()
//{
//	char* arr = "We are happy.";
//	int length = strlen(arr);
//	fun(arr, length);
//	printf("%s\n", arr);
//	return 0;
//}

//int main()
//{
//	int num = 0;
//	int f1 = 0;
//	int f2 = 1;
//	int f3 = 0;
//	scanf("%d", &num);
//	while (1)
//	{
//		if (f2 == num)
//		{
//			printf("%d\n", 0);
//			break;
//		}
//		else if(f2>num)
//		{
//			if (abs(f2 - num) > abs(f1 - num))
//			{
//				printf("%d\n", abs(f1 - num));
//				break;
//			}
//			else
//			{
//				printf("%d\n", abs(f2 - num));
//				break;
//			}
//		}
//		f3 = f1 + f2;
//		f1 = f2;
//		f2 = f3;
//	}
//	return 0;
//}


//void replaceSpace(char* str, int length)
//{
//    char arr[20] = { 0 };
//    int i = 0;
//    char* p = str;
//    while (*p)
//    {
//        if ((*p) != ' ')
//        {
//            arr[i] = *p;
//            i++;
//            p++;
//        }
//        else
//        {
//            arr[i] = '%';
//            i++;
//            arr[i] = '2';
//            i++;
//            arr[i] = '0';
//            i++;
//            p++;
//        }
//    }
//    int j = 0;
//    while (arr[j])
//    {
//        str[j] = arr[j];
//        j++;
//    }
//}

//int main()
//{
//    char str[20] = "we are happy.";
//    replaceSpace(str, 1);
//    printf("%s\n", str);
//    return 0;
//}

//int main()
//{
//	int arr[]={ 1,1,2,2,3,3,4,4,5,6 };
//	int i = 0;
//	int ret = 0;
//	int num1 = 0;
//	int num2 = 0;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	for (i = 0; i < sz; i++)
//		ret ^= arr[i];
//	for (i = 0; i < 32; i++)
//	{
//		if (((ret >> i)&1) == 1)
//			break;
//	}
//	int pos = i;
//	for (i = 0; i < sz; i++)
//	{
//		if (((arr[i] >> pos)&1) == 1)
//			num1 ^= arr[i];
//	}
//	num2 = ret ^ num1;
//	printf("%d %d\n", num1, num2);
//}



//#define EXCHANGE(x) ((((x)&0xAAAAAAAA)>>1)|(((x)&0x55555555)<<1))
//
//int main()
//{
//	int a = 5;
//	printf("%d\n", EXCHANGE(a));
//	return 0;
//}

// 写一个宏，计算结构体中某变量相对于首地址的偏移，并给出说明
//#define OffSetOf(StructType, MemberName) (size_t)&(((StructType *)0)->MemberName)
//
//struct student
//{
//	char a;
//	char c;
//	int b;
//};
//
//int main()
//{
//	struct student s = { 'a',4,'c' };
//	int tmp= OffSetOf(struct student, a);
//	printf("%d\n", tmp);
//	tmp = OffSetOf(struct student, b);
//	printf("%d\n", tmp);
//	tmp = OffSetOf(struct student, c);
//	printf("%d\n", tmp);
//	return 0;
//}

//int main()
//{
//	FILE* pfRead = fopen("test1.txt", "r");
//	if (pfRead == NULL)
//	{
//		perror("open file for reading");
//		return 1;
//	}
//	FILE* pfWrite = fopen("test2.txt", "w");
//	if (pfWrite == NULL)
//	{
//		perror("open file for writting");
//		fclose(pfRead);
//		pfRead = NULL;
//		return 1;
//	}
//
//	int ch = 0;
//	while ((ch = fgetc(pfRead)) != EOF)
//	{
//		fputc(ch, pfWrite);
//	}
//	fclose(pfRead);
//	pfRead = NULL;
//	fclose(pfWrite);
//	pfWrite = NULL;
//	return 0;
//}



//struct Stu
//{
//	char name[20];
//	int age;
//	float score;
//};



//
//int main()
//{
//	struct Stu s = {"zhangsan", 20, 66.5f};
//	FILE*pf = fopen("test.txt", "w");
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//	fprintf(pf, "%s %d %f", s.name, s.age, s.score);
//
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}


//
//int main()
//{
//	struct Stu s = { 0 };
//	FILE*pf = fopen("test.txt", "r");
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//	fscanf(pf, "%s %d %f", s.name, &(s.age), &(s.score));
//	printf("%s %d %f\n", s.name, s.age, s.score);
//
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

//int main()
//{
//	char input[20] = { 0 };
//	FILE* pf = fopen("test.txt", "r");
//	if (pf == NULL)
//	{
//		perror("opne file for reading");
//		return 1;
//	}
//	//读数据
//	fgets(input, 20, pf);
//	printf("%s", input);
//
//	fgets(input, 20, pf);
//	printf("%s", input);
//	fclose(pf);
//	pf = NULL;
//
//	return 0;
//}


//int main()
//{
//	char input[20] = { 0 };
//	FILE* pf = fopen("test.txt", "r");
//	if (pf == NULL)
//	{
//		perror("opne file for reading");
//		return 1;
//	}
//	//读数据
//	fgets(input, 3, pf);
//	printf("%s\n", input);
//	fgets(input, 3, pf);
//	printf("%s\n", input);
//
//	fclose(pf);
//	pf = NULL;
//
//	return 0;
//}


//int main()
//{
//	char arr[5] = "qwe";
//	FILE* pf = fopen("test.txt", "w");
//	if (pf == NULL)
//	{
//		perror("opne file for writting");
//		return 1;
//	}
//	写数据
//	fputs(arr, pf);
//	fputs("haha\n", pf);
//
//	fclose(pf);
//	pf = NULL;
//
//	return 0;
//}

//int main()
//{
//	//打开文件
//	FILE* pf = fopen("test.txt", "r");
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//	//读文件
//	int ch = fgetc(pf);
//	printf("%c\n", ch);
//	ch = fgetc(pf);
//	printf("%c\n", ch);
//	ch = fgetc(pf);
//	printf("%c\n", ch);
//	ch = fgetc(pf);
//	printf("%c\n", ch);
//	//关闭文件
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}


//int main()
//{
//	//打开文件
//	FILE* pf = fopen("test.txt", "w");	
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//	//写文件
//	fputc('a', pf);
//	fputc('b', pf);
//	fputc('c', pf);
//	fputc('d', pf);
//	fputc('e', pf);
//	//关闭文件
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}


//int main()
//{
//	char a = 'A';
//	FILE* pf = fopen("test.txt", "w");
//	fwrite(&a, sizeof(char), 1, pf);
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}


//enum State
//{
//	VALID,
//	INVALID
//}state = VALID;
//
//int my_atoi(const char* str)
//{
//	int flag = 0;
//	state = INVALID;
//	if (str == NULL)
//		return 0;
//	while (isspace(*str))
//	{
//		str++;
//	}
//	if (*str == '+')
//	{
//		flag = 1;
//		str++;
//	}
//	else if (*str == '-')
//	{
//		flag = -1;
//		str++;
//	}
//	long long ret = 0;
//	while (isdigit(*str))
//	{
//		ret = ret * 10 + flag * (*str - '0');
//		if (ret > INT_MAX || ret < INT_MIN)
//			{
//				ret = 0;
//				return (int)ret;
//			}
//		str++;
//	}
//	return (int)ret;
//}
//
//int main()
//{
//	//""
//	char*p = "   -123@";
//	int ret = my_atoi(p);//-123
//	printf("%d\n", ret);
//
//	return 0;
//}


//int main()
//{
//	char arr[10] = { 0 };
//	FILE* pf = fopen("test.txt", "w");
//	if (pf == NULL)
//		{
//			return 1;
//		}
//	fputs("ABCDEF", pf);
//	fgets(arr,1,pf);
//	printf("%c\n", arr[0]);
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}


//struct Stu
//{
//	char name[20];
//	int age;
//	float score;
//};
//
//int main()
//{
//	struct Stu s = { 0 };
//	FILE* pf = fopen("test.txt", "r");
//	if (pf == NULL)
//	{
//		perror("open file for read");
//		return 1;
//	}
//	fread(&s, sizeof(struct Stu), 1, pf);
//	printf("%s %d %f\n", s.name, s.age, s.score);
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}


//#define PRINT(FORMAT,X) printf("the value of "#X" is "FORMAT"\n",X)
//int main()
//{
//	int a = 12;
//	float b = 0.5;
//	PRINT("%d",a);
//	PRINT("%f", b);
//	return 0;
//}


//extern int add(int x, int y);
//int main()
//{
//	int i = 0;
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	FILE* pf = fopen("log.txt", "w");
//	if (pf == NULL)
//	{
//		perror("open file for writting");
//		return 1;
//	}
//	for (i = 0; i < 10; i++)
//	{
//		fprintf(pf, "file:%s line:%d date:%s time:%s: %d\n", __FILE__, __LINE__, __DATE__, __TIME__, arr[i]);
//	}
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}