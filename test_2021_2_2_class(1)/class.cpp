// �޸Ľṹ�������
// #pragma pack(1)
#include <iostream>
using namespace std;

int* ptr = NULL;
class SeqList
{
public:
	SeqList()
	{
		_size = 0;
		p = (int*)malloc(sizeof(int));
		cout << "SeqList()" << endl;
	}
	~SeqList()
	{
		free(p);
		p = NULL;
		_size = 0;
		cout << "~SeqList()" << endl;
	}
	int _size;
	int* p;
};

class Data
{
public:
	Data(int day, int month)
	{
		_day = day;
		_month = month;
		cout << "Data(int day, int month)" << endl;
	}

	Data()
	{
		cout << "Data()" << endl;
	}
private:
	int _day;
	int _month;

	SeqList sl;
};

int main()
{
	Data d;
	return 0;
}

//void test()
//{
//	SeqList sl;
//	ptr = sl.p;
//}
//int main()
//{
//	test();
//	return 0;
//}


//// ��
//class Student
//{
//public:
//	int add(int x, int y)
//	{
//		return x + y;
//	}
//private:
//	char _name[10];
//	int _age;
//};
//
//// �ṹ��
//struct A
//{
//	char a;
//	int c;
//	int b;
//	char d;
//};
//
//// ����
//union B
//{
//	int a;
//	char b;
//};
//
//int main()
//{
//	B obj;
//	obj.a = 1;
//	if (obj.b)
//		printf("С��");
//	else
//		printf("���");
//
//	return 0;
//
//
//	//A a;
//	//cout << sizeof(B) << endl;
//	//cout << (char*)&a.b - (char*)&a << endl;
//}