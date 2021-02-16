#include <iostream>
using namespace std;

// 类模板
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

// 如果在类外定义类模板的成员函数，需要加上泛型的声明
template<class T1, class T2, class T3>
// 类模板名字不是真正的类，而实例化的结果才是真正的类
// Vector类名，Vector<int>才是类型
void Date<T1, T2, T3>::Display()
{
	cout << _year << "-" << _month << "-" << _day << endl;
}

int main()
{
	// 类模板只能进行-显式-实例化
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
//	// 隐式实例化
//	Swap(a, b);
//	Date d1(2020, 1, 1);
//	Date d2(2021, 12, 31);
//	// 显式实例化
//	Swap<Date>(d1, d2);
//}
//
//// 专门处理int的加法函数
//int Add(int left, int right) {
//	return left + right;
//}
//
//// 通用加法函数
//template<class T>
//T Add(T left, T right)
//{
//	return left + right;
//}
//
//void test2()
//{
//	Add(1, 2); // 与非模板函数匹配，编译器不需要特化
//	Add<int>(1, 2); // 调用编译器特化的Add版本
//}
//
//int main()
//{
//	//test1();
//	test2();
//
//	return 0;
//}