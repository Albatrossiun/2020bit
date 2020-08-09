//# @FileName:test.c
//# @author:ZhaoXinYi
//# @version:0.0.1
//# @Date:2020.08.07
//# @BSD

#define _CRT_SECURE_NO_WARNINGS 1	//最好放在源文件的第一行
//在newc++file.cpp里面添加这一句，创建的每一个源文件都会自己自动携带一句
//vs编译器认为不安全的函数 scanf strcpy

//ctrl+F5 运行快捷键

//按住ctrl滑动鼠标可以改变字体大小 工具-选项-字体和颜色

//写法已经过时
//void main()
//{
//
//}

// main函数是程序的入口，程序是从main函数的第一行开始执行的
// main函数只有一个，一个工程！工程！工程只能有且只有一个main函数

// scanf-输入 printf-输出 一对

#include <stdio.h>	// std-标准 i-input o-output


int main()	// int 返回值类型为整型   main是函数名
{
	int num = 0;
	scanf("%d\n",&num);
	printf("%d\n",num);
	printf("hello bit\n");	// printf 是库函数，c语言自身提供的函数，需要引入头文件
	printf("\n");
	printf("\n");
	printf("%d\n",sizeof(char));		// 1byte
	printf("%d\n",sizeof(short));		// 2byte					只能表示0-65535
	printf("%d\n",sizeof(int));			// 4byte
	printf("%d\n",sizeof(long));		// 4byte(32位)/8byte(64位)	标准规定：sizeof(long) >= sizeof(int)
	printf("%d\n",sizeof(long long));	// 8byte					标准规定：sizeof(long long) >= sizeof(long)
	printf("%d\n",sizeof(float));		// 4byte
	printf("%d\n",sizeof(double));		// 8byte

	return 0;
}

//数据类型
//char 字符数据类型
//short 短整型
//int 整型
//long 长整型
//long long 更长的整型
//float 单精度浮点数	123.45 12.345*10 1234.5*10^-1
//double 双精度浮点数


//计算机中最小的单位
//比特位 bit
//字节 byte
//KB
//MB
//GB
//TB

//二进制 1 0 一个存储大小就是一个比特位
//规定：8个bit = 1个byte
//规定：1个MB=1024个KB

//c语言有个关键字 sizeof(类型)--计算类型创建变量所开辟空间的大小