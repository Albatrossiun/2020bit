#include <iostream>
using namespace std;

// ȫȱʡ�����в�������Ĭ��ֵ
void fun1(int a = 10)
{
	cout << "fun1:" << a << endl;
}

void fun2(int a = 1, int b = 2, int c = 3, int d = 4, int e = 5)
{
	cout << "fun2:" << a << " " << b << " " << c << " " << d << " " << e << endl;
}

// ��ȱʡ�����ֲ�������Ĭ��ֵ
void fun3(int a, int b = 2, int c = 3)
{
	cout << "fun3:" << a << " " << b << " " << c << endl;
}
// ע1������Ĭ��ֵ������ҵ�������������Ĭ��ֵ���м䲻���м��
// ��������������
// void fun3(int a = 1, int b, int c = 3);
// void fun3(int a = 1, int b = 2, int c);
// void fun3(int a, int b = 2, int c);

// ע2��ȱʡ���������ں��������Ͷ�����ͬʱ����
//void fun4(int a, int b = 2);

void fun4(int a, int b = 2)
{
	cout << "fun4:" << a << " " << b << endl;
}

// ��������
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


// ����
void fun()
{
	const int a = 10;
	const int& ra1 = a;
	// 1.���� int& ra1 = a; 


	const int& ra2 = 10;
	// 2.���� 10Ϊ�����޸ĵĳ��� int& ra2 = 10;

	double b = 2.5;
	// ���Ͳ�ͬ����Ҫʹ��const
	const int& ra3 = b;
	// ��double��int����ת��ʱ������һ���Ѿ���2.5ת��Ϊ2����ʱ����
	// ��ʱ����ʱ�������Կ�����������Ҫʹ��const
	// 3.���� int& ra3 = b;
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

// ����һ���ṹ��
typedef struct stu
{
	char name[5];
	int age;
}stu;

int main()
{
	stu Stu;
	// �ṹ�������rStu
	stu& rStu = Stu;
	// �ṹ���ָ��pSru
	stu* pStu = &Stu;

	cout << "�ṹ�������rStu���ڴ��СΪ��" << sizeof(rStu) << endl;
	cout << "�ṹ���ָ��pStu���ڴ��СΪ��" << sizeof(pStu) << endl;

	return 0;
}