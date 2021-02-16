#include <iostream>
using namespace std;

//////////////////////////////////////////////////////////////
// new/delete
// ��λnew���ʽ
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
	// ptr����ָ���ֻ��������Date������ͬ��С��һ�οռ�
	// ����������һ��������Ϊû��ִ��-���캯��-
	Date* ptr = (Date*)malloc(sizeof(Date));
	// ��λnew���ʽ
	new(ptr) Date;	// �޲ι��캯��
	new(ptr) Date(2021, 2, 13);	// �вι��캯��

	return 0;
}


//class Date
//{
//public:
//	// Ĭ�Ϲ��캯��
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
//	// ����һ���Զ������͵�һ���������С�Ŀռ�
//	// �����޲�/ȫȱʡ���캯��
//	Date* ptr1 = new Date;
//	// �����вι��캯��
//	Date* ptr2 = new Date(1,1,1);
//
//	// ����һ���Զ������ͣ������ࣩ�������ռ�
//	// �Զ�����-Ĭ�Ϲ��캯��-���������ĳ�ʼ������
//	// ���û��Ĭ�Ϲ��캯��������������
//	Date* ptr3 = new Date[2];
//
//	// �ͷ��Զ������͵Ŀռ�
//	// 1.�ȵ�����������������Դ
//	// 2.���ͷſռ�
//	delete ptr1;
//	delete ptr2;
//	delete[] ptr3;
//
//	return 0;
//}




///////////////////////////////////////////////////////////////
//��Ԫ 

// ǰ������
//class Date;
//class Time
//{
//	// ����������Ϊʱ�������Ԫ��
//	// �����������о�ֱ�ӷ���Time���е�˽�г�Ա����
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
//		// ֱ�ӷ���ʱ����˽�еĳ�Ա����
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
//static���� 
//class Date
//{
//public:
//	// ��̬��Ա����
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
//// ��̬�ĳ�Ա����һ��Ҫ��������г�ʼ����
//int Date::_dcount = 0;
//// ��̬��Ա������ʼ�����
//
//int main()
//{
//	Date d;
//	// ��̬��Ա�������ʷ�����
//	// 1.�������
//	cout << d.getdcount() << endl;
//	// 2.���� + �������޶��� 
//	cout << Date::getdcount() << endl;
//
//	return 0;
//}





/////////////////////////////////////////////////////////////////
//class Date
//{
//public:
//	// �޲ε�Ĭ�Ϲ��캯��
//	Date()
//	{}
//private:
//	// �Ǿ�̬��Ա�����������ڳ�Ա����ʱ��ȱʡֵ
//	// ��Ա��������ʱ������һ����ֵ���������Ƕ���
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
//	// Time��ȫȱʡ��Ĭ�Ϲ��캯��
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
//	Time t1(1);	// ��������
//	Time t2 = 2;	// �������󣺵��ι��캯������ʽ����ת��
//					// ----> ���ù��캯������һ���������� + ��������(ͨ���������󿽱�����)
//	t2 = 3;	// ���ø�ֵ������
//}
//
//class Date
//{
//public:
//	Date()
//	// ÿ����Ա����ֻ���ڳ�ʼ���б��г���һ��
//	// ����ĳ�Ա��������ĵط�������ʼ���б� 
//	// ���������ڳ�ʼ���б����Զ������Զ����Ա��Ĭ�Ϲ�����ɳ�ʼ��
//	// ��ʼ���б�û�г�ʼ��-�Զ����Ա
//	{
//		// ����Time���е�Ĭ�Ϲ��캯�����������и�ֵ����
//		_time = Time(10);
//	}
//private:
//	// �Զ����Ա
//	Time _time;
//};
//
//int main()
//{
//	test();
//
//	return 0;
//}