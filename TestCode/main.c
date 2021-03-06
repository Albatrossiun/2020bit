#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include <ctype.h>
#include <math.h>
#include <windows.h>

void reverse(int* nums, int start, int end)
{
    while (start <= end)
    {
        nums[start] = nums[start] ^ nums[end];  //  与自身[异或]始终为零
        nums[end] = nums[start] ^ nums[end];
        nums[start] = nums[start] ^ nums[end];
        start++;
        end--;
    }
}

void rotate(int* nums, int numsSize, int k)
{
    k %= numsSize;
    reverse(nums, 0, numsSize - k - 1);
    reverse(nums, numsSize - k, numsSize - 1);
    reverse(nums, 0, numsSize - 1);
}

int main()
{
    int i = 0;
    int arr[] = { 1,2,3,4,5,6 };
    for (i = 0; i < 6; i++)
    {
        printf("%d ", arr[i]);
    }
    rotate(arr, 6, 2);
    printf("\n");
    for (i = 0; i < 6; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}

////删除排序数组中的重复项
//int main()
//{
//	int arr[] = { 0,1,1,2,2,3,3,3,4 };	//	arr[]={ 0,1,2,3,4 }
//	int size = sizeof(arr) / sizeof(arr[0]);
//	int start = 0;
//	int end = start;
//	int index = 1;
//	while (end < size)
//	{
//		if (arr[start] != arr[end])
//		{
//			start = end;
//			arr[index++] = arr[start];
//		}
//		end++;
//	}
//	int i = 0;
//	for (i = 0; i < size ; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}

////寻找两个不同的数字->arr[]={1,1,2,2,3,4}
//int* singleNumbers(int* nums, int numsSize, int* returnSize) {
//	int num = 0;
//	int* p = nums;
//	for (int i = 0; i < numsSize; i++) {
//		num = num ^ nums[i];
//	}
//	int index = 0;
//	while (index < 32) {
//		if (((num >> index) & 0x01) != 0x00) {
//			break;
//		}
//		index++;
//	}
//	int a = 0;
//	int b = 0;
//	for (int i = 0; i < numsSize; i++) {
//		int tmp = nums[i];
//		if (((tmp >> index) & 0x01) == 0x01) {
//			a = a ^ tmp;
//		}
//		else {
//			b = b ^ tmp;
//		}
//	}
//	int* ret = (int*)malloc(sizeof(int) * 2);
//	ret[0] = a;
//	ret[1] = b;
//	*returnSize = 2;
//	return ret;
//}

//int main()
//{
//	int arr[] = { 1,1,2,2,3,3,4,5 };	//	4->0100	5->0101
//	int i = 0;
//	int tmp = arr[0];
//	for (i = 1; i < 8; i++)
//	{
//		tmp = tmp ^ arr[i];
//	}
//	int tmp1 = 0;
//	for (i = 0; i < 8; i++)
//	{
//		if ((arr[i] & 1) == 0)
//		{
//			tmp1 ^= arr[i];
//		}
//	}
//	int tmp2 = tmp1;
//	for (i = 0; i < 8; i++)
//	{
//		tmp2 = tmp2 ^ arr[i];
//	}
//	printf("%d %d\n", tmp1, tmp2);
//	return 0;
//}

//int main()
//{
//	char* arr = "abcdefg";
//	printf("%s\n", strchr(arr, 'd'));
//	return 0;
//}

//int main()
//{
//	int a = 3;
//	int b;
//	b = (a > 5) ? 3 : 5;
//	printf("%d\n", b);
//	return 0;
//}

//int main()
//{
//	int i = 0, a = 0, b = 2, c = 3, d = 4;
//	//i = a++ && ++b && d++;
//	i = a++||++b||d++;
//	//	1	3	3	4	1
//	printf("a = %d\n b = %d\n c = %d\nd = %d\ni = %d\n", a, b, c, d, i);
//	return 0;
//}

//int main()
//{
//	int a = 10;
//	int x = ++a;
//	int y = --a;
//	printf("%d %d %d\n", a, x, y);	//	10	11	10
//	return 0;
//}
//int main()
//{
//	int a = 10;
//	int y = a--;
//	printf("%d %d\n", a, y);
//	return 0;
//}

//void test1(int arr[])
//{
//	printf("%d\n", sizeof(arr));	//	指针变量的大小
//}
//void test2(char ch[])
//{
//	printf("%d\n", sizeof(ch));	//	指针变量的大小
//}
//int main()
//{
//	int arr[10] = { 0 };
//	char ch[10] = { 0 };
//	printf("%d\n", sizeof(arr));	//	40
//	printf("%d\n", sizeof(ch));	//	10
//	test1(arr);	//	4
//	test2(ch);	//	4
//	return 0;
//}

////赋值操作符
//int main()
//{
//	int a = -10;
//	int* p = NULL;
//	printf("%d\n", !2);
//	printf("%d\n", !0);
//	a = -a;
//	p = &a;
//	printf("%d\n", sizeof(a));
//	printf("%d\n", sizeof(int));	//	字节
//	printf("%d\n", sizeof a);	//	这样写行不行？
//	return 0;
//}


//int main()
//{
//	int num = 15;
//	int i = 0;
//	int count = 0;//计数
//	while (num)
//	{
//		count++;
//		num = num & (num - 1);
//	}
//	//	1111&1110=1110 1110&1101=1100 1100&1011=1000 1000&0111=0000
//	//	0110&0101=0100 0100&0011=0000
//	printf("二进制中1的个数 = %d\n", count);
//	return 0;
//}
//int main()
//{
//	int num = 15;
//	int i = 0;
//	int num1 = 32;
//	int count = 0;
//	while (num1)
//	{
//		if (((num >> (i++))&1) == 1)
//			count++;
//		num1--;
//	}
//	printf("%d\n", count);
//	return 0;
//}
//int main()
//{
//	int num = 15;	//	1111
//	int count = 0;
//	while (1)
//	{
//		if (num == 0)
//			break;
//		if (num % 2 == 1)
//		{
//			count++;
//		}
//		num = num / 2;
//	}
//	printf("%d\n", count);
//	return 0;
//}
//int main()
//{
//	int num = 10;	//	1010、0101、0010、0001
//	int count = 0;	//	计数
//	while (num)
//	{
//		if (num % 2 == 1)
//			count++;
//		num = num / 2;
//	}
//	printf("二进制中1的个数 = %d\n", count);
//	return 0;
//}

//int main()
//{
//	int a = 1;	//	001
//	int b = 5;	//	101
//	a = a ^ b;	//	100
//	b = a ^ b;	//	001
//	a = a ^ b;	//	101
//	printf("a = %d b = %d\n", a, b);
//	return 0;
//}

//int main()
//{
//	int num1 = 1;	//	001
//	int num2 = 2;	//	010
//	int a, b, c;
//	a = num1 & num2;
//	b = num1 | num2;
//	c = num1 ^ num2;
//	printf("%d %d %d\n", a, b, c);	//	0	3	3
//	return 0;
//}

//void fun(int* arr, int size)
//{
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < size-1; i++)
//	{
//		for (j = 0; j < size - 1 - i; j++)
//		{
//			if (arr[j] >= arr[j + 1])
//			{
//				int tmp = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = tmp;
//			}
//		}
//	}
//}
//int main()
//{
//	int arr[] = { 3,5,1,7,9,2 };
//	int size = sizeof(arr) / sizeof(arr[0]);
//	int i = 0;
//	for (i = 0; i < size; i++)
//	{
//		printf("%d", arr[i]);
//	}
//	printf("\n");
//	fun(arr, size);
//	for (i = 0; i < size; i++)
//	{
//		printf("%d", arr[i]);
//	}
//	return 0;
//}

//int main()
//{
//	int arr[] = { 1,2,4,6,8 };
//	printf("%d\n", sizeof(arr));	//	20
//	printf("%d\n", sizeof(*(&arr)));	//	20
//	printf("%d\n", sizeof(arr[0]));	//	4
//	return 0;
//}

//int fib(int n) {
//	int result;
//	int pre_result;
//	int next_older_result;
//	result = pre_result = 1;
//	while (n > 2)
//	{
//		n -= 1;
//		next_older_result = pre_result;
//		pre_result = result;
//		result = pre_result + next_older_result;
//	}
//	return result;
//}
//求第n个斐波那契数
//1、1、2、3、5、8、13、21、34、……
//int fib(int n) {
//	if (n <= 2)
//		return 1;
//	else
//		return fib(n - 1) + fib(n - 2);
//}
//
//int main()
//{
//	int n = 8;
//	printf("%d\n", fib(n));
//	return 0;
//}

//int Strlen(const char* str)
//{
//	int count = 0;
//	if (*str == '\0')
//		return 0;
//	else
//	{
//		count = 1 + Strlen(str + 1);
//		return count;
//	}
//}
//
//int main()
//{
//	char* p = "abcdef";
//	int len = Strlen(p);
//	printf("%d\n", len);
//	return 0;
//}

//void print(int num)
//{
//	if (num > 9)
//	{
//		print(num / 10);
//	}
//	printf("%d", (num % 10));
//}
//
//int main()
//{
//	int num = 1357;
//	print(num);
//	return 0;
//}

//int main()
//{
//	printf("%d", printf("%d", printf("%d", 43)));
//	//结果是啥？
//	return 0;
//}

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