#include <iostream>
using namespace std;

// ��ģ��
template<class T1,class T2,class T3>
class Date
{
public:
	Date(T1 y, T2 m, T3 d)
		:_year(y)
		, _month(m)
		, _day(d)
	{}

	void Display();
private:
	T1 _year;
	T2 _month;
	T3 _day;
};

// ��������ⶨ����ģ��ĳ�Ա��������Ҫ���Ϸ��͵�����
template<class T1, class T2, class T3>
// ��ģ�����ֲ����������࣬��ʵ�����Ľ��������������
// Vector������Vector<int>��������
void Date<T1, T2, T3>::Display()
{
	cout << _year << "-" << _month << "-" << _day << endl;
}

int main()
{
	// ��ģ��ֻ�ܽ���-��ʽ-ʵ����
	Date<int, int, int> d(2020, 1, 1);
	d.Display();
	return 0;
}








//template<typename T>
//void Swap(T& left, T& right)
//{
//	T temp = left;
//	left = right;
//	right = temp;
//}
//
//class Date
//{
//public:
//	Date(int y,int m,int d)
//		:_year(y)
//		, _month(m)
//		,_day(d)
//	{}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//void test1()
//{
//	int a = 1;
//	int b = 2;
//	// ��ʽʵ����
//	Swap(a, b);
//	Date d1(2020, 1, 1);
//	Date d2(2021, 12, 31);
//	// ��ʽʵ����
//	Swap<Date>(d1, d2);
//}
//
//// ר�Ŵ���int�ļӷ�����
//int Add(int left, int right) {
//	return left + right;
//}
//
//// ͨ�üӷ�����
//template<class T>
//T Add(T left, T right)
//{
//	return left + right;
//}
//
//void test2()
//{
//	Add(1, 2); // ���ģ�庯��ƥ�䣬����������Ҫ�ػ�
//	Add<int>(1, 2); // ���ñ������ػ���Add�汾
//}
//
//int main()
//{
//	//test1();
//	test2();
//
//	return 0;
//}