#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include <ctype.h>
#include <math.h>

void fun(char* arr, int length)
{
	int count = 0;
	int i = 0;
	for (i = 0; i < length; i++)
	{
		if (arr[i] == ' ')
		{
			count++;
		}
	}
	int size = length + 2 * count - 1;
	for (i = length-1 ; i >= 0; i--)
	{
		if (arr[i] == ' ')
		{
			arr[size--] = '0';
			arr[size--] = '2';
			arr[size--] = '%';
		}
		else
		{
			arr[size--] = arr[i];
		}
	}
}

int main()
{
	char* arr = "We are happy.";
	int length = strlen(arr);
	fun(arr, length);
	printf("%s\n", arr);
	return 0;
}

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

// дһ���꣬����ṹ����ĳ����������׵�ַ��ƫ�ƣ�������˵��
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
//	//������
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
//	//������
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
//	д����
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
//	//���ļ�
//	FILE* pf = fopen("test.txt", "r");
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//	//���ļ�
//	int ch = fgetc(pf);
//	printf("%c\n", ch);
//	ch = fgetc(pf);
//	printf("%c\n", ch);
//	ch = fgetc(pf);
//	printf("%c\n", ch);
//	ch = fgetc(pf);
//	printf("%c\n", ch);
//	//�ر��ļ�
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}


//int main()
//{
//	//���ļ�
//	FILE* pf = fopen("test.txt", "w");	
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//	//д�ļ�
//	fputc('a', pf);
//	fputc('b', pf);
//	fputc('c', pf);
//	fputc('d', pf);
//	fputc('e', pf);
//	//�ر��ļ�
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