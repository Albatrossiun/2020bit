#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include <ctype.h>

int main()
{
	FILE* pfRead = fopen("test1.txt", "r");
	if (pfRead == NULL)
	{
		perror("open file for reading");
		return 1;
	}
	FILE* pfWrite = fopen("test2.txt", "w");
	if (pfWrite == NULL)
	{
		perror("open file for writting");
		fclose(pfRead);
		pfRead = NULL;
		return 1;
	}

	int ch = 0;
	while ((ch = fgetc(pfRead)) != EOF)
	{
		fputc(ch, pfWrite);
	}
	fclose(pfRead);
	pfRead = NULL;
	fclose(pfWrite);
	pfWrite = NULL;
	return 0;
}



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