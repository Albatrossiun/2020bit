#include <iostream>
#include <string>
using namespace std;


void test1()
{
	string s;
	int size = s.size();
	int cap = s.capacity();
	cout << "初始容量为：" << cap << endl;
	for (int i = 0; i < 200; i++)
	{
		s.push_back(i);
		if (cap != s.capacity())
		{
			cap = s.capacity();
			cout << "修改为：" << cap << endl;
		}
	}
}


void test2()
{
	string s;
	int size = s.size();
	// 使用reserve()提前开好空间，节省频繁增容的开销，提高代码效率
	s.reserve(200);
	int cap = s.capacity();
	cout << "初始容量：" << cap << endl;

	for (int i = 0; i < 200; i++)
	{
		s.push_back(i);
		if (cap != s.capacity())
		{
			cap = s.capacity();
			cout << "修改为：" << cap << endl;
		}
	}
}


// 非类string成员函数
void test3()
{
	// string关系运算符
	// 大小关系比较规则：按照ASCII码逐位进行比较，和长度无关
	// 不是类string的成员函数
	string s1("123");
	string s2("1234");
	string s3("3");
	bool ret = s1 > s2;		// false
	ret = s1 > s3;		// false
	ret = s2 > s3;		// false
}


// 非类string成员函数
void test4()
{
	// 运算符重载输入、输出函数
	// string支持运算符<< >>
	// operator<<
	// operator>>
	string s4;
	// cin一遇到空格就结束
	//cin >> s4;
	cout << s4;
	// 如果读取的内容有空格，可以使用getline
	// getline第三个参数：结束标志默认为换行符，也可指定getline(cin, s4, ',');
	getline(cin, s4);
	cout << s4;
}


int main()
{
	
	// 构造函数
	string str1;	// ""——无参构造
	string str2("abc");	// "abc"
	string str3 = "ABC";	// "ABC"
	string str4("12345", 4);	// "1234"
	string str5(str4);	// "1234"——拷贝构造
	string str6(str5, 2, 2);	// "34"
	string str7(5, 'i');	// "iiiii"

	
	string str("012345");
	// size：返回有效字符的个数
	int ret = str.size();
	// length：返回有效字符的个数
	ret = str.length();
	// capacity：可以存放的最大有效字符的个数
	ret = str.capacity();
	// max_size：当前代码可以使用的内存大小
	size_t maxSize = str.max_size();
	// clear：只清空内容，不改变容量
	str.clear();
	ret = str.size();
	ret = str.capacity();
	

	// resize()
	string str = "012345";
	int size = str.size();
	int cap = str.capacity();
	// 1.当n>size，且n>capacity：增容，新的位置赋值，默认为‘\0’
	str.resize(20);
	size = str.size();
	cap = str.capacity();
	// 2.当n<size：只修改size
	str.resize(10);
	size = str.size();
	cap = str.capacity();
	// 3.当n>size，且n<capacity
	str.resize(30, 'a');
	size = str.size();
	cap = str.capacity();
	

	test1();	// 15 31 47 70 105 157 235
	test2();	// 207


	// reserve()
	string str = "012345";
	int size = str.size();
	int cap = str.capacity();
	// reserve(n)：修改容量
	str.reserve(20);
	size = str.size();
	cap = str.capacity();
	// 当n<size时，不做任何修改
	str.reserve(5);
	size = str.size();
	cap = str.capacity();
	

	// 字符串遍历方法：
	// 1.迭代器
	string str = "abcdefg";
	string::iterator it = str.begin();
	while (it != str.end())
	{
		cout << *it << "-";
		it++;	// 用法类似于指针
	}
	cout << endl;
	// 2.operator[]：可读可写接口
	for (int i = 0; i < str.size(); i++)
	{
		cout << str.operator[](i) << "-";
		// 简写形式：cout << str[i] << "-";
		str[i] = 'a';	// 修改操作
	}
	cout << endl;
	// 3.at：可读可写接口。与operator[]不同的是：如果越界访问，会抛异常
	for (int i = 0; i < str.size(); i++)
	{
		cout << str.at(i) << "-";
		// 简写形式：cout << str[i] << "-";
	}
	cout << endl;
	// 4.范围for：可读可写接口。如果需要修改，则接受类型为引用类型
	for (const auto& ch : str)
	{
		cout << ch << "-";
	}
	cout << endl;
	

	// push_back只能尾插 一个字符
	// append可以尾插 一串字符
	// 最常用：operator+=
	string s;
	s.push_back('a');	// a
	s.append(2, 'b');	// abb
	s.append("cd");		// abbcd
	string s2;
	s2.append(s);		// abbcd
	string s3;
	s3.append(s, 2, 3);	// bcd
	char strArr[] = "12345";
	s3.append(strArr, strArr + 3);		// bcd123
	s3.append(s2.begin(), s2.end());	// bcd123abbcd
	string s4;
	s4 += '1';		// 1
	s4 += "23";		// 123
	s4 += s;		// 123abbcd
	

	// string::insert
	string s5;
	s5.insert(0, s2);				// abbcd
	s5.insert(1, s2, 1, 2);			// abbbbcd
	s5.insert(s5.end(), 3, '1');	// abbbbcd111
	s5.insert(s5.begin(), strArr, strArr + 2);	// 12abbbbcd111


	// string::assign  赋值操作
	s5.assign("111");		// 111
	// 等同于，但原理不同，下面调用了构造函数
	s5 = "12345";			// 12345


	// string::erase  删除字符操作
	s5.erase(0, 2);			// 345
	s5.erase(s5.begin());	// 45
	// s5.erase(s5.end())——越界操作
	s5.erase(s5.begin(), s5.end());		// ""
	

	// string::replace  替换字符操作
	string s6("012345");
	s6.replace(2, 4, "aa");			// 01aa
	s6.replace(s6.begin(), s6.end() - 1, "2");		// 2a 


	// swap()和string::swap()
	string s7("012");
	// 类的成员函数
	s7.swap(s6);	
	// 全局string类型的交换函数：内部调用string的成员函数swap()实现交换
	swap(s6, s7);	
	int a = 1, b = 2;
	// 处理所有数据类型的全局交换函数，底层与“全局string类型的交换函数”不同
	swap(a, b);


	// string::c_str：只读接口，返回const char*，不可修改
	// string::data：同上
	const char* ptr1 = s7.c_str();		
	const char* ptr2 = s7.data();
	// 返回地址相同


	// string::find  查找字符操作
	string s8("abcba");
	// 正向查找字符a  pos1 = 0
	size_t pos1 = s8.find("a");	
	// 反向查找字符a  pos2 = 4
	size_t pos2 = s8.rfind("a");


	// string::find应用实例
	string file1 = "test.tar.gz.zip";
	size_t pos3 = file1.rfind(".");
	// string::substr：截取字符串的一部分
	// string::substr  第一个参数：起始位置 第二个参数：截取长度
	// str1 = "zip"
	string str1 = file1.substr(pos3 + 1, file1.size() - pos3 - 1);
	// str2 = "zip"
	// 长度为100，有多少拷多少
	string str2 = file1.substr(pos3 + 1, 100);


	return 0;
}
