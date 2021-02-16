#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
using namespace std;


class String
{
public:
	// 无参构造函数
	String()
		// 15 表示初始化的有效数据的个数
		// 15+1 表示还需存放一个'\0'
		:_str(new char[16])
		, _size(0)
		, _capacity(0)
	{
		_str[_size] = '\0';
		_capacity = 15;
	}


	// 有参构造函数
	String(const char* str)
	{
		_size = strlen(str);
		// 预留位置存放'\0'
		// 在堆上开辟空间
		_str = new char[_size + 1];
		// '\0'利用strcpy也直接拷贝过来
		strcpy(_str, str);
		_capacity = _size;
	}
	/*
	这种方法不正确
	如果一个字符串是常量字符串
	则在析构函数清理资源的时候
	会delete代码段的空间，导致代码异常
	delete只能释放堆上的空间
	String(char* str)
		:_str(str)
		,_size(strlen(str))
		,_capacity(strlen(str))
	{}
	*/


	// c_str() 返回字符串的首地址
	const char* c_str() const
	{
		return _str;
	}


	// 拷贝构造函数——深拷贝
	String(const String& str)
		:_str(new char[str._capacity + 1])
		, _size(str._size)
		, _capacity(str._capacity)
	{
		strcpy(_str, str._str);
	}


	// 拷贝构造函数——深拷贝
	// 现代写法
	// 优点：利用构造函数代码复用
	/*
	String(const String& str)
		// 如果不初始化_str，在析构函数清理空间会出现问题
		:_str(nullptr)
		, _size(0)
		, _capacity(0)
	{
		// 调用构造函数
		String tmp(str._str);
		Swap(tmp);
	}
	void Swap(String& str)
	{
		swap(_str, str._str);
		swap(_size, str._size);
		swap(_capacity, str._capacity);
	}
	*/


	// 赋值运算符=重载
	String& operator=(const String& str)
	{
		if (this != &str)
		{
			// 开空间
			char* tmp = new char[str._capacity + 1];
			// 内容拷贝
			strcpy(tmp, str._str);
			// 释放原有空间
			delete[] _str;

			_str = tmp;
			_size = str._size;
			_capacity = str._capacity;
		}
		return *this;
	}
	// 现代写法，代码复用
	/*
	String& operator=(String str)
	{
		// 不能规避自己对自己赋值
		// 形参传参调用拷贝构造函数，开好空间，拷好内容
		Swap(str);
		return *this;
	}
	String& operator=(const String& str)
	{
		String tmp(str);
		Swap(tmp);
		return *this;
	}
	*/


	// 尾插操作
	void pushBack(const char& ch)
	{
		// 检查容量
		if (_size == _capacity)
		{
			size_t newcapacity = _capacity == 0 ? 15 : 2 * _capacity;
			// 增容操作
			reserve(newcapacity);
		}
		// 尾插
		_str[_size] = ch;
		// 更新参数
		_size++;
		// 字符串末尾还有一个\0
		_str[_size] = '\0';
	}
	void reserve(size_t newcapacity)
	{
		if (newcapacity > _capacity)
		{
			// 开空间
			char* tmp = new char[newcapacity + 1];
			// 拷贝数据
			strcpy(tmp, _str);
			// 释放原有空间
			delete[] _str;

			_str = tmp;
			// 更新容量
			_capacity = newcapacity;
		}
	}


	// 迭代器：一种访问容器元素的机制，体现封装的特性
	// 不需要关注容器的实现细节，就可以直接访问(可读可写)元素
	// 使用方式：类似于指针的操作
	//			 1.解引用 ---> 获取指定位置的内容
	//			 2.位置移动 ---> 指向其他位置
	// string迭代器：通过指针实现
	// 实现迭代器后，就可以使用范围for
	typedef char* iterator;
	typedef const char* const_iterator;
	// 可读可写接口
	iterator begin()
	{
		// 返回第一个元素的位置
		return _str;
	}
	iterator end()
	{
		// 最后一个元素的下一个位置
		return _str + _size;
	}
	// 可读不可写接口
	const_iterator begin() const
	{
		// 返回第一个元素的位置
		return _str;
	}
	const_iterator end() const
	{
		// 最后一个元素的下一个位置
		return _str + _size;
	}


	// operator[]
	// 可读可写接口
	char& operator[](size_t pos)
	{
		if (pos < _size)
			return _str[pos];
	}
	// 仅可读接口
	const char& operator[](size_t pos) const
	{
		if (pos < _size)
			return _str[pos];
	}


	// size()：返回有效个数
	size_t size() const
	{
		return _size;
	}


	// append()
	void Append(const char* str)
	{
		int len = strlen(str);
		// 检查容量
		if (_size + len > _capacity)
		{
			reserve(_size + len);
		}
		// 尾插
		strcpy(_str + _size, str);
		// 修改参数
		_size += len;
	}


	// operator+=( 字符 )
	String& operator+=(const char& ch)
	{
		pushBack(ch);
		return *this;
	}


	// operator+=( 字符串 )
	String& operator+=(const char* str)
	{
		Append(str);
		return *this;
	}


	// insert( 字符 )
	void insert(size_t pos, const char& ch)
	{
		// 判断插入位置是否有效
		if (pos > _size)
			return;
		// 判断容量
		if (_size == _capacity)
		{
			size_t newcapacity = _capacity == 0 ? 15 : 2 * _capacity;
			reserve(newcapacity);
		}
		// 移动数据[pos,_size]：从后往前移动防止覆盖
		// 不要忘记'\0'
		size_t end = _size + 1;
		while (end > pos)
		{
			_str[end] = _str[end - 1];
			end--;
		}
		// 插入元素
		_str[pos] = ch;
		// 修改参数
		_size++;
	}
	/*
	错误代码：
	void insert(size_t pos, const char& ch)
	{
		if (pos > _size)
			return;
		if (_size == _capacity)
		{
			size_t newcapacity = _capacity == 0 ? 15 : 2 * _capacity;
			reserve(newcapacity);
		}
		size_t end = _size;
		// end>=pos：有可能出现越界访问
		// end=0仍然会进入循环
		// end--：导致end为负数
		// 出现越界访问
		while (end >= pos)
		{
			_str[end + 1] = _str[end];
			end--;
		}
		_str[pos] = ch;
		_size++;
	}
	*/


	// insert( 字符串 )
	void insert(size_t pos, const char* str)
	{
		if (pos > _size)
			return;
		int len = strlen(str);
		if (_size + len > _capacity)
		{
			reserve(_size + len);
		}
		size_t end = _size + len;
		while (end > pos + len - 1)
		{
			_str[end] = _str[end - len];
			--end;
		}
		// 不能使用strcpy，因为会把'\0'拷贝过去覆盖_str[pos+len]的值
		for (int i = 0; i < len; i++)
		{
			_str[i + pos] = str[i];
		}
		_size += len;
	}


	// resize()
	void resize(size_t n, const char& ch = '\0')
	{
		// 判断是否扩容
		if (n > _capacity)
			reserve(n);
		// 判断是否放大size，初始化扩容后的数据
		if (n > _size)
			memset(_str + _size, ch, n - _size);
		_size = n;
		_str[_size] = '\0';
	}


	// popBack() 尾删
	// 如果_size=0，进入erase中pos=-1(max值)
	// 此时pos>_size，不会进入if循环，因此不会进行删除操作
	void popBack()
	{
		erase(_size - 1, 1);
	}
	/*
	void popBack()
	{
		if (_size > 0)
			_str[--_size] = '\0';
	}
	*/


	// erase() 删除字符串
	void erase(size_t pos, size_t len)
	{
		if (pos < _size)
		{
			// 判断删除的长度是否大于等于从pos开始的所有的字符
			if (pos + len >= _size)
			{
				_size = pos;
				_str[_size] = '\0';
			}
			// 移动数据
			else
			{
				// i<=_size 不用再次进行补'\0'操作
				for (int i = pos + len; i <= _size; i++)
				{
					_str[pos++] = _str[i];
				}
				// 更新参数
				_size -= len;
			}
		}
	}


	// find() 正向查找返回该字符串的第一次出现的首地址
	size_t find(const char* str)
	{
		char* ptr = strstr(_str, str);
		if (ptr)
			// 两地址相减，得到相对于起始位置的偏移量
			return ptr - _str;
		else
			return npos;
	}


	// 析构函数
	~String()
	{
		if (_str)
		{
			delete[] _str;
			_size = _capacity = 0;
			_str = nullptr;
		}
	}


private:
	char* _str;
	size_t _size;
	size_t _capacity;


public:
	// 静态成员遍历，须在类外初始化
	static const size_t npos;
};


// 类外初始化完成
const size_t String::npos = -1;


// operator+()
String operator+(const String& s, const char& ch)
{
	String tmp(s);
	tmp += ch;
	return tmp;
}
String operator+(const String& s, const char* str)
{
	String tmp(s);
	tmp += str;
	return tmp;
}
String operator+(const String& s, const String& str)
{
	String tmp(s);
	tmp += str.c_str();
	return tmp;
}


// 输出运算符<<重载
ostream& operator<<(ostream& cout, const String& str)
{
	// 1.范围for
	// 才能输出'\0'
	for (const auto& ch : str)
	{
		cout << ch;
	}

	// 2.operator[]
	for (int i = 0; i < str.size(); i++)
	{
		cout << str[i];
	}

	// 3.迭代器
	String::const_iterator it = str.begin();
	while (it != str.end())
	{
		cout << *it;
		it++;
	}


	return cout;
}
/*
// 写法与标准库中的cout不一致，还要输出'\0'
ostream& operator<<(ostream& cout, const String& str)
{
	cout << str.c_str() << endl;
	return cout;
}
*/


// 打印字符串：只读
void printString(const String& str)
{
	// 迭代器遍历
	String::const_iterator it = str.begin();
	while (it != str.end())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;
}


// 迭代器遍历
void test1()
{
	String s = "123";
	String::iterator it = s.begin();
	while (it != s.end())
	{
		cout << *it << " ";
		// 修改数据
		*it = 'a';
		it++;
	}
	cout << endl;
	it = s.begin();
	while (it != s.end())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;
}


// 迭代器实现范围for
// 编译器在编译时，把范围for转化为迭代器的遍历方式
// 如果在遍历过程中，需要进行写操作，接收类型需要为引用类型
void test2()
{
	String s = "123";
	// const 不可以进行修改操作
	for (const auto& ch : s)
	{
		cout << ch << " ";
	}
	cout << endl;
	// auto& 引用：可以直接修改数据
	for (auto& ch : s)
	{
		cout << ch << " ";
		ch = 'a';
	}
	cout << endl;
	// 只能修改形参
	for (auto ch : s)
	{
		cout << ch << " ";
	}
	cout << endl;
}


// find()应用实例
void test3()
{
	String s("01234567");
	size_t pos = s.find("02");
	if (pos == String::npos)
	{
		cout << "not find" << endl;
	}
}


int main()
{
	String s("01234");


	return 0;
}