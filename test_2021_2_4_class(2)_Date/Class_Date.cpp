#include <iostream>
using namespace std;


class Date
{
public:
	// 获取某年某月的天数
	int GetMonthDay(int year, int month)
	{
		static int days[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		int day = days[month];
		if (month == 2
			&& ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
		{
			day += 1;
		}
		return day;
	}

	// 全缺省的构造函数
	Date(int year = 1, int month = 1, int day = 1)
	{
		if (year <= 0 || month <= 0 || month >= 13 || day <= 0 
			|| day > GetMonthDay(year, month))
		{
			_year = 1;
			_month = 1;
			_day = 1;
			cout << "日期无效，设为默认值1-1-1" << endl;
		}
		else
		{
			_year = year;
			_month = month;
			_day = day;
			cout << "日期有效，设置成功" << endl;
		}
	}

	// 拷贝构造函数
	// d2(d1)
	Date(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
		cout << "拷贝构造成功" << endl;
	}

	// 赋值运算符重载
	// d2 = d3 -> d2.operator=(&d2, d3)
	Date& operator=(const Date& d)
	{
		if (this != &d)
		{
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}
		return *this;
	}

	// 析构函数
	// ~Date();

	// 日期+=天数
	Date& operator+=(int day)
	{
		if (day < 0)
			return *this -= -day;
		_day += day;
		while (day > GetMonthDay(_year, _day))
		{
			_day -= GetMonthDay(_year, _month);
			_month++;
			if (_month == 13)
			{
				_year++;
				_month = 1;
			}
		}
		return *this;
	}

	// 日期+天数
	Date operator+(int day)
	{
		Date copy(*this);
		copy += day;
		return copy;
	}

	// 日期-天数
	Date operator-(int day)
	{
		Date copy(*this);
		copy -= day;
		return copy;
	}

	// 日期-=天数
	Date& operator-=(int day)
	{
		if (day < 0)
			return *this += -day;
		_day -= day;
		while (_day <= 0)
		{
			_month--;
			if (_month == 0)
			{
				_year--;
				_month = 12;
			}
			_day += GetMonthDay(_year, _month);
		}
		return *this;
	}

	// 前置++
	Date& operator++()
	{
		return *this += 1;
	}

	// 后置++
	Date operator++(int)
	{
		Date copy(*this);
		*this += 1;
		return copy;
	}

	// 后置--
	Date operator--(int)
	{
		Date copy(*this);
		*this -= 1;
		return copy;
	}

	// 前置--
	Date& operator--()
	{
		return *this -= 1;
	}

	// >运算符重载
	bool operator>(const Date& d)
	{
		if (_year > d._year)
		{
			return true;
		}
		else if (_year == d._year)
		{
			if (_month > d._month)
			{
				return true;
			}
			else if (_month == d._month)
			{
				if (_day > d._day)
				{
					return true;
				}
			}
		}
		return false;
	}

	// ==运算符重载
	bool operator==(const Date& d)
	{
		return _year == d._year && _month == d._month && _day == d._day;
	}

	// >=运算符重载
	inline bool operator >= (const Date& d)
	{
		return *this > d || *this == d;
	}

	// <运算符重载
	bool operator < (const Date& d)
	{
		return !(*this >= d);
	}

	// <=运算符重载
	bool operator <= (const Date& d)
	{
		return !(*this > d);
	}

	// !=运算符重载
	bool operator != (const Date& d)
	{
		return !(*this == d);
	}

	// 日期-日期 返回天数
	int operator-(const Date& d)
	{
		// 自家的次数就是相差的天数
		Date max = *this;
		Date min = d;
		int flag = 1;
		if (max < min)
		{
			max = d;
			min = *this;
			flag = -1;
		}
		int day = 0;
		while (min < max)
		{
			min++;
			day++;
		}
		return flag * day;
	}

private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	Date d1(2021, 1, 1);
	Date d2(2021, 2, 29);
	return 0;
}