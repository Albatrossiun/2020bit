// �޸Ľṹ�������
// #pragma pack(1)
#include <iostream>
using namespace std;











// ���������
class Date
{
public:
	Date(int month = 1, int day = 1)
	{
		_month = month;
		_day = day;
		cout << "Date(int month = 1, int day = 1)" << endl;
	}

	bool operator==(const Date& d2)
	{
		return _month == d2._month && _day == d2._day;
		cout << "bool operator==(const Date& d2)" << endl;
	}

	Date& operator=(const Date& d)
	{
		if (this != &d)
		{
			_month = d._month;
			_day = d._day;
			cout << "void operator=(const Date& d)" << endl;
		}
		return *this;
		//return d;
	}
private:
	int _month;
	int _day;
};

int main()
{
	Date d1(1, 1);
	Date d2(2, 2);
	Date d3(3, 3);
	//������Ҫע����ǣ����������thisָ��ĵ��ú����Ķ���
	//if (d1 == d2)
	
	//d1 = d2;
	d1.operator=(d2.operator=(d3));

	/*
	if (d1.operator==(d2))
	{
		cout << "==" << endl;
	}
	else
	{
		cout << "!=" << endl;
	}
	*/

	return 0;
}











//int* ptr = NULL;
//class SeqList
//{
//public:
//	SeqList(int a)
//	{
//		_size = 0;
//		p = (int*)malloc(sizeof(int));
//		cout << "SeqList()" << endl;
//	}
//	~SeqList()
//	{
//		free(p);
//		p = NULL;
//		_size = 0;
//		cout << "~SeqList()" << endl;
//	}
//	int _size;
//	int* p;
//};
//
//class Data
//{
//public:
//	// �޲εĹ��캯��
//	Data()
//	{
//		cout << "Data()" << endl;
//	}
//	Data(int day, int month)
//	// �вεĹ��캯��
//	{
//		_day = day;
//		_month = month;
//		cout << "Data(int day, int month)" << endl;
//	}
//	// �������캯��
//	Data(const Data& d)
//	{
//		_day = d._day;
//		_month = d._month;
//	}
//private:
//	int _day;
//	int _month;
//};
//
//int main()
//{
//	//SeqList sl1(0);
//	//SeqList sl2(sl1);
//	//return 0;
//	Data d1;
//	Data d2(d1);
//	return 0;
//}

//int main()
//{
//	Data d;
//	return 0;
//}
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