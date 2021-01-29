#include <iostream>
using namespace std;

// 全缺省：所有参数都有默认值
void fun1(int a = 10)
{
	cout << "fun1:" << a << endl;
}

void fun2(int a = 1, int b = 2, int c = 3, int d = 4, int e = 5)
{
	cout << "fun2:" << a << " " << b << " " << c << " " << d << " " << e << endl;
}

// 半缺省：部分参数设置默认值
void fun3(int a, int b = 2, int c = 3)
{
	cout << "fun3:" << a << " " << b << " " << c << endl;
}
// 注1：设置默认值必须从右到左依次连续赋默认值，中间不能有间隔
// 以下命名均错误
// void fun3(int a = 1, int b, int c = 3);
// void fun3(int a = 1, int b = 2, int c);
// void fun3(int a, int b = 2, int c);

// 注2：缺省参数不能在函数声明和定义中同时出现
//void fun4(int a, int b = 2);

void fun4(int a, int b = 2)
{
	cout << "fun4:" << a << " " << b << endl;
}

// 函数重载
void Add(int a, char b)
{
	cout << "Add(int a, char b)" << endl;
}

void Add(char b, int a)
{
	cout << "Add(char b, int a)" << endl;
}

//int main()
//{
//	int a = 1;
//	char b = 'b';
//	Add(b, a);
//	Add(a, b);
//	return 0;
//}


// 引用
void fun()
{
	const int a = 10;
	const int& ra1 = a;
	// 1.报错 int& ra1 = a; 


	const int& ra2 = 10;
	// 2.报错 10为不可修改的常量 int& ra2 = 10;

	double b = 2.5;
	// 类型不同，需要使用const
	const int& ra3 = b;
	// 从double到int类型转换时，存在一个已经将2.5转化为2的临时变量
	// 此时的临时变量可以看作常量，故要使用const
	// 3.报错 int& ra3 = b;
}
//int main()
//{
//	fun();
//	return 0;
//}

//int& add(int& a, int& b)
//{
//	int c = a + b;
//	return c;
//}
//
//void test()
//{
//	int a = 10;
//	int b = 10;
//	int& ra = add(a, b);
//	add(a, b);
//	cout << a << endl;
//	cout << ra << endl;
//}

// 定义一个结构体
typedef struct stu
{
	char name[5];
	int age;
}stu;

int main()
{
	stu Stu;
	// 结构体的引用rStu
	stu& rStu = Stu;
	// 结构体的指针pSru
	stu* pStu = &Stu;

	cout << "结构体的引用rStu的内存大小为：" << sizeof(rStu) << endl;
	cout << "结构体的指针pStu的内存大小为：" << sizeof(pStu) << endl;

	return 0;
}