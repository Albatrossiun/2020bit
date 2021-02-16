#include <iostream>
using namespace std;

//////////////////////////////////////////////////////////////
// new/delete
// 定位new表达式
class Date
{
public:
	Date()
		: _year(1)
		, _month(1)
		, _day(1)
	{}

	Date(int year, int month, int day)
		:_year(year)
		, _month(month)
		, _day(day)
	{}

private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	// ptr现在指向的只不过是与Date对象相同大小的一段空间
	// 还不能算是一个对象，因为没有执行-构造函数-
	Date* ptr = (Date*)malloc(sizeof(Date));
	// 定位new表达式
	new(ptr) Date;	// 无参构造函数
	new(ptr) Date(2021, 2, 13);	// 有参构造函数

	return 0;
}


//class Date
//{
//public:
//	// 默认构造函数
//	Date(int year = 2020, int month = 1, int day = 1)
//		:_year(year)
//		, _month(month)
//		, _day(day)
//	{}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main()
//{
//	// 开辟一个自定义类型的一个日期类大小的空间
//	// 调用无参/全缺省构造函数
//	Date* ptr1 = new Date;
//	// 调用有参构造函数
//	Date* ptr2 = new Date(1,1,1);
//
//	// 开辟一个自定义类型（日期类）的连续空间
//	// 自动调用-默认构造函数-完成日期类的初始化操作
//	// 如果没有默认构造函数，编译器报错
//	Date* ptr3 = new Date[2];
//
//	// 释放自定义类型的空间
//	// 1.先调用析构函数清理资源
//	// 2.再释放空间
//	delete ptr1;
//	delete ptr2;
//	delete[] ptr3;
//
//	return 0;
//}




///////////////////////////////////////////////////////////////
//友元 

// 前置声明
//class Date;
//class Time
//{
//	// 声明日期类为时间类的友元类
//	// 则在日期类中就直接访问Time类中的私有成员变量
//	friend class Date; 
//
//public:
//	Time(int hour = 1, int minute = 1, int second = 1)
//		: _hour(hour)
//		, _minute(minute)
//		, _second(second)
//	{}
//
//private:
//	int _hour;
//	int _minute;
//	int _second;
//};
//class Date
//{
//public:
//	Date(int year = 1900, int month = 1, int day = 1)
//		: _year(year)
//		, _month(month)
//		, _day(day)
//	{}
//
//	void SetTimeOfDate(int hour, int minute, int second)
//	{
//		// 直接访问时间类私有的成员变量
//		_t._hour = hour;
//		_t._minute = minute;
//		_t._second = second;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//	Time _t;
//};

//class Date
//{
//	friend ostream& operator<<(ostream& _cout, const Date& d);
//	friend istream& operator>>(istream& _cin, Date& d);
//
//public:
//	Date(int year = 1, int month = 1, int day = 1)
//		: _year(year)
//		, _month(month)
//		, _day(day)
//	{}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//ostream& operator<<(ostream& _cout, const Date& d) {
//	_cout << d._year << "-" << d._month << "-" << d._day;
//
//	return _cout;
//}
//istream& operator>>(istream& _cin, Date& d) {
//	_cin >> d._year >> d._month >> d._day;
//
//	return _cin;
//}
//int main()
//{
//	Date d;
//	Date d1;
//	cin >> d >> d1;
//	cout << d << endl << d1 << endl;
//	return 0;
//}



//////////////////////////////////////////////////////////
//static变量 
//class Date
//{
//public:
//	// 静态成员函数
//	static int getdcount()
//	{
//		return _dcount;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//
//	static int _dcount;
//};
//
//// 静态的成员变量一定要在类外进行初始化。
//int Date::_dcount = 0;
//// 静态成员变量初始化完成
//
//int main()
//{
//	Date d;
//	// 静态成员变量访问方法：
//	// 1.对象访问
//	cout << d.getdcount() << endl;
//	// 2.类名 + 作用域限定符 
//	cout << Date::getdcount() << endl;
//
//	return 0;
//}





/////////////////////////////////////////////////////////////////
//class Date
//{
//public:
//	// 无参的默认构造函数
//	Date()
//	{}
//private:
//	// 非静态成员变量，可以在成员声明时给缺省值
//	// 成员变量声明时，给定一个初值。但并不是定义
//	int _year = 1;
//	int _month = 1;
//	int _day = 1;
//};
//
//int main()
//{
//	Date d;
//	return 0;
//}















///////////////////////////////////////////////////////////////////////////////
//class Time
//{
//public:
//	// Time类全缺省的默认构造函数
//	Time(int a=10)
//		:_a(a)
//	{}
//
//	Time& operator=(const Time d)
//	{
//		_a = d._a;
//		return *this;
//	}
//private:
//	int _a;
//};
//
//void test()
//{
//	Time t1(1);	// 创建对象
//	Time t2 = 2;	// 创建对象：单参构造函数的隐式类型转换
//					// ----> 调用构造函数创建一个匿名对象 + 拷贝构造(通过匿名对象拷贝构造)
//	t2 = 3;	// 调用赋值操作符
//}
//
//class Date
//{
//public:
//	Date()
//	// 每个成员变量只能在初始化列表中出现一次
//	// 对象的成员变量定义的地方——初始化列表 
//	// 编译器会在初始化列表中自动调用自定义成员的默认构造完成初始化
//	// 初始化列表没有初始化-自定义成员
//	{
//		// 利用Time类中的默认构造函数对类对象进行赋值操作
//		_time = Time(10);
//	}
//private:
//	// 自定义成员
//	Time _time;
//};
//
//int main()
//{
//	test();
//
//	return 0;
//}