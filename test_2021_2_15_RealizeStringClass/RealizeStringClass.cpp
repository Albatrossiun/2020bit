#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
using namespace std;


class String
{
public:
	// �޲ι��캯��
	String()
		// 15 ��ʾ��ʼ������Ч���ݵĸ���
		// 15+1 ��ʾ������һ��'\0'
		:_str(new char[16])
		, _size(0)
		, _capacity(0)
	{
		_str[_size] = '\0';
		_capacity = 15;
	}


	// �вι��캯��
	String(const char* str)
	{
		_size = strlen(str);
		// Ԥ��λ�ô��'\0'
		// �ڶ��Ͽ��ٿռ�
		_str = new char[_size + 1];
		// '\0'����strcpyҲֱ�ӿ�������
		strcpy(_str, str);
		_capacity = _size;
	}
	/*
	���ַ�������ȷ
	���һ���ַ����ǳ����ַ���
	������������������Դ��ʱ��
	��delete����εĿռ䣬���´����쳣
	deleteֻ���ͷŶ��ϵĿռ�
	String(char* str)
		:_str(str)
		,_size(strlen(str))
		,_capacity(strlen(str))
	{}
	*/


	// c_str() �����ַ������׵�ַ
	const char* c_str() const
	{
		return _str;
	}


	// �������캯���������
	String(const String& str)
		:_str(new char[str._capacity + 1])
		, _size(str._size)
		, _capacity(str._capacity)
	{
		strcpy(_str, str._str);
	}


	// �������캯���������
	// �ִ�д��
	// �ŵ㣺���ù��캯�����븴��
	/*
	String(const String& str)
		// �������ʼ��_str����������������ռ���������
		:_str(nullptr)
		, _size(0)
		, _capacity(0)
	{
		// ���ù��캯��
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


	// ��ֵ�����=����
	String& operator=(const String& str)
	{
		if (this != &str)
		{
			// ���ռ�
			char* tmp = new char[str._capacity + 1];
			// ���ݿ���
			strcpy(tmp, str._str);
			// �ͷ�ԭ�пռ�
			delete[] _str;

			_str = tmp;
			_size = str._size;
			_capacity = str._capacity;
		}
		return *this;
	}
	// �ִ�д�������븴��
	/*
	String& operator=(String str)
	{
		// ���ܹ���Լ����Լ���ֵ
		// �βδ��ε��ÿ������캯�������ÿռ䣬��������
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


	// β�����
	void pushBack(const char& ch)
	{
		// �������
		if (_size == _capacity)
		{
			size_t newcapacity = _capacity == 0 ? 15 : 2 * _capacity;
			// ���ݲ���
			reserve(newcapacity);
		}
		// β��
		_str[_size] = ch;
		// ���²���
		_size++;
		// �ַ���ĩβ����һ��\0
		_str[_size] = '\0';
	}
	void reserve(size_t newcapacity)
	{
		if (newcapacity > _capacity)
		{
			// ���ռ�
			char* tmp = new char[newcapacity + 1];
			// ��������
			strcpy(tmp, _str);
			// �ͷ�ԭ�пռ�
			delete[] _str;

			_str = tmp;
			// ��������
			_capacity = newcapacity;
		}
	}


	// ��������һ�ַ�������Ԫ�صĻ��ƣ����ַ�װ������
	// ����Ҫ��ע������ʵ��ϸ�ڣ��Ϳ���ֱ�ӷ���(�ɶ���д)Ԫ��
	// ʹ�÷�ʽ��������ָ��Ĳ���
	//			 1.������ ---> ��ȡָ��λ�õ�����
	//			 2.λ���ƶ� ---> ָ������λ��
	// string��������ͨ��ָ��ʵ��
	// ʵ�ֵ������󣬾Ϳ���ʹ�÷�Χfor
	typedef char* iterator;
	typedef const char* const_iterator;
	// �ɶ���д�ӿ�
	iterator begin()
	{
		// ���ص�һ��Ԫ�ص�λ��
		return _str;
	}
	iterator end()
	{
		// ���һ��Ԫ�ص���һ��λ��
		return _str + _size;
	}
	// �ɶ�����д�ӿ�
	const_iterator begin() const
	{
		// ���ص�һ��Ԫ�ص�λ��
		return _str;
	}
	const_iterator end() const
	{
		// ���һ��Ԫ�ص���һ��λ��
		return _str + _size;
	}


	// operator[]
	// �ɶ���д�ӿ�
	char& operator[](size_t pos)
	{
		if (pos < _size)
			return _str[pos];
	}
	// ���ɶ��ӿ�
	const char& operator[](size_t pos) const
	{
		if (pos < _size)
			return _str[pos];
	}


	// size()��������Ч����
	size_t size() const
	{
		return _size;
	}


	// append()
	void Append(const char* str)
	{
		int len = strlen(str);
		// �������
		if (_size + len > _capacity)
		{
			reserve(_size + len);
		}
		// β��
		strcpy(_str + _size, str);
		// �޸Ĳ���
		_size += len;
	}


	// operator+=( �ַ� )
	String& operator+=(const char& ch)
	{
		pushBack(ch);
		return *this;
	}


	// operator+=( �ַ��� )
	String& operator+=(const char* str)
	{
		Append(str);
		return *this;
	}


	// insert( �ַ� )
	void insert(size_t pos, const char& ch)
	{
		// �жϲ���λ���Ƿ���Ч
		if (pos > _size)
			return;
		// �ж�����
		if (_size == _capacity)
		{
			size_t newcapacity = _capacity == 0 ? 15 : 2 * _capacity;
			reserve(newcapacity);
		}
		// �ƶ�����[pos,_size]���Ӻ���ǰ�ƶ���ֹ����
		// ��Ҫ����'\0'
		size_t end = _size + 1;
		while (end > pos)
		{
			_str[end] = _str[end - 1];
			end--;
		}
		// ����Ԫ��
		_str[pos] = ch;
		// �޸Ĳ���
		_size++;
	}
	/*
	������룺
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
		// end>=pos���п��ܳ���Խ�����
		// end=0��Ȼ�����ѭ��
		// end--������endΪ����
		// ����Խ�����
		while (end >= pos)
		{
			_str[end + 1] = _str[end];
			end--;
		}
		_str[pos] = ch;
		_size++;
	}
	*/


	// insert( �ַ��� )
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
		// ����ʹ��strcpy����Ϊ���'\0'������ȥ����_str[pos+len]��ֵ
		for (int i = 0; i < len; i++)
		{
			_str[i + pos] = str[i];
		}
		_size += len;
	}


	// resize()
	void resize(size_t n, const char& ch = '\0')
	{
		// �ж��Ƿ�����
		if (n > _capacity)
			reserve(n);
		// �ж��Ƿ�Ŵ�size����ʼ�����ݺ������
		if (n > _size)
			memset(_str + _size, ch, n - _size);
		_size = n;
		_str[_size] = '\0';
	}


	// popBack() βɾ
	// ���_size=0������erase��pos=-1(maxֵ)
	// ��ʱpos>_size���������ifѭ������˲������ɾ������
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


	// erase() ɾ���ַ���
	void erase(size_t pos, size_t len)
	{
		if (pos < _size)
		{
			// �ж�ɾ���ĳ����Ƿ���ڵ��ڴ�pos��ʼ�����е��ַ�
			if (pos + len >= _size)
			{
				_size = pos;
				_str[_size] = '\0';
			}
			// �ƶ�����
			else
			{
				// i<=_size �����ٴν��в�'\0'����
				for (int i = pos + len; i <= _size; i++)
				{
					_str[pos++] = _str[i];
				}
				// ���²���
				_size -= len;
			}
		}
	}


	// find() ������ҷ��ظ��ַ����ĵ�һ�γ��ֵ��׵�ַ
	size_t find(const char* str)
	{
		char* ptr = strstr(_str, str);
		if (ptr)
			// ����ַ������õ��������ʼλ�õ�ƫ����
			return ptr - _str;
		else
			return npos;
	}


	// ��������
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
	// ��̬��Ա���������������ʼ��
	static const size_t npos;
};


// �����ʼ�����
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


// ��������<<����
ostream& operator<<(ostream& cout, const String& str)
{
	// 1.��Χfor
	// �������'\0'
	for (const auto& ch : str)
	{
		cout << ch;
	}

	// 2.operator[]
	for (int i = 0; i < str.size(); i++)
	{
		cout << str[i];
	}

	// 3.������
	String::const_iterator it = str.begin();
	while (it != str.end())
	{
		cout << *it;
		it++;
	}


	return cout;
}
/*
// д�����׼���е�cout��һ�£���Ҫ���'\0'
ostream& operator<<(ostream& cout, const String& str)
{
	cout << str.c_str() << endl;
	return cout;
}
*/


// ��ӡ�ַ�����ֻ��
void printString(const String& str)
{
	// ����������
	String::const_iterator it = str.begin();
	while (it != str.end())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;
}


// ����������
void test1()
{
	String s = "123";
	String::iterator it = s.begin();
	while (it != s.end())
	{
		cout << *it << " ";
		// �޸�����
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


// ������ʵ�ַ�Χfor
// �������ڱ���ʱ���ѷ�Χforת��Ϊ�������ı�����ʽ
// ����ڱ��������У���Ҫ����д����������������ҪΪ��������
void test2()
{
	String s = "123";
	// const �����Խ����޸Ĳ���
	for (const auto& ch : s)
	{
		cout << ch << " ";
	}
	cout << endl;
	// auto& ���ã�����ֱ���޸�����
	for (auto& ch : s)
	{
		cout << ch << " ";
		ch = 'a';
	}
	cout << endl;
	// ֻ���޸��β�
	for (auto ch : s)
	{
		cout << ch << " ";
	}
	cout << endl;
}


// find()Ӧ��ʵ��
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