#include <iostream>
#include <string>
using namespace std;


void test1()
{
	string s;
	int size = s.size();
	int cap = s.capacity();
	cout << "��ʼ����Ϊ��" << cap << endl;
	for (int i = 0; i < 200; i++)
	{
		s.push_back(i);
		if (cap != s.capacity())
		{
			cap = s.capacity();
			cout << "�޸�Ϊ��" << cap << endl;
		}
	}
}


void test2()
{
	string s;
	int size = s.size();
	// ʹ��reserve()��ǰ���ÿռ䣬��ʡƵ�����ݵĿ�������ߴ���Ч��
	s.reserve(200);
	int cap = s.capacity();
	cout << "��ʼ������" << cap << endl;

	for (int i = 0; i < 200; i++)
	{
		s.push_back(i);
		if (cap != s.capacity())
		{
			cap = s.capacity();
			cout << "�޸�Ϊ��" << cap << endl;
		}
	}
}


// ����string��Ա����
void test3()
{
	// string��ϵ�����
	// ��С��ϵ�ȽϹ��򣺰���ASCII����λ���бȽϣ��ͳ����޹�
	// ������string�ĳ�Ա����
	string s1("123");
	string s2("1234");
	string s3("3");
	bool ret = s1 > s2;		// false
	ret = s1 > s3;		// false
	ret = s2 > s3;		// false
}


// ����string��Ա����
void test4()
{
	// ������������롢�������
	// string֧�������<< >>
	// operator<<
	// operator>>
	string s4;
	// cinһ�����ո�ͽ���
	//cin >> s4;
	cout << s4;
	// �����ȡ�������пո񣬿���ʹ��getline
	// getline������������������־Ĭ��Ϊ���з���Ҳ��ָ��getline(cin, s4, ',');
	getline(cin, s4);
	cout << s4;
}


int main()
{
	
	// ���캯��
	string str1;	// ""�����޲ι���
	string str2("abc");	// "abc"
	string str3 = "ABC";	// "ABC"
	string str4("12345", 4);	// "1234"
	string str5(str4);	// "1234"������������
	string str6(str5, 2, 2);	// "34"
	string str7(5, 'i');	// "iiiii"

	
	string str("012345");
	// size��������Ч�ַ��ĸ���
	int ret = str.size();
	// length��������Ч�ַ��ĸ���
	ret = str.length();
	// capacity�����Դ�ŵ������Ч�ַ��ĸ���
	ret = str.capacity();
	// max_size����ǰ�������ʹ�õ��ڴ��С
	size_t maxSize = str.max_size();
	// clear��ֻ������ݣ����ı�����
	str.clear();
	ret = str.size();
	ret = str.capacity();
	

	// resize()
	string str = "012345";
	int size = str.size();
	int cap = str.capacity();
	// 1.��n>size����n>capacity�����ݣ��µ�λ�ø�ֵ��Ĭ��Ϊ��\0��
	str.resize(20);
	size = str.size();
	cap = str.capacity();
	// 2.��n<size��ֻ�޸�size
	str.resize(10);
	size = str.size();
	cap = str.capacity();
	// 3.��n>size����n<capacity
	str.resize(30, 'a');
	size = str.size();
	cap = str.capacity();
	

	test1();	// 15 31 47 70 105 157 235
	test2();	// 207


	// reserve()
	string str = "012345";
	int size = str.size();
	int cap = str.capacity();
	// reserve(n)���޸�����
	str.reserve(20);
	size = str.size();
	cap = str.capacity();
	// ��n<sizeʱ�������κ��޸�
	str.reserve(5);
	size = str.size();
	cap = str.capacity();
	

	// �ַ�������������
	// 1.������
	string str = "abcdefg";
	string::iterator it = str.begin();
	while (it != str.end())
	{
		cout << *it << "-";
		it++;	// �÷�������ָ��
	}
	cout << endl;
	// 2.operator[]���ɶ���д�ӿ�
	for (int i = 0; i < str.size(); i++)
	{
		cout << str.operator[](i) << "-";
		// ��д��ʽ��cout << str[i] << "-";
		str[i] = 'a';	// �޸Ĳ���
	}
	cout << endl;
	// 3.at���ɶ���д�ӿڡ���operator[]��ͬ���ǣ����Խ����ʣ������쳣
	for (int i = 0; i < str.size(); i++)
	{
		cout << str.at(i) << "-";
		// ��д��ʽ��cout << str[i] << "-";
	}
	cout << endl;
	// 4.��Χfor���ɶ���д�ӿڡ������Ҫ�޸ģ����������Ϊ��������
	for (const auto& ch : str)
	{
		cout << ch << "-";
	}
	cout << endl;
	

	// push_backֻ��β�� һ���ַ�
	// append����β�� һ���ַ�
	// ��ã�operator+=
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


	// string::assign  ��ֵ����
	s5.assign("111");		// 111
	// ��ͬ�ڣ���ԭ��ͬ����������˹��캯��
	s5 = "12345";			// 12345


	// string::erase  ɾ���ַ�����
	s5.erase(0, 2);			// 345
	s5.erase(s5.begin());	// 45
	// s5.erase(s5.end())����Խ�����
	s5.erase(s5.begin(), s5.end());		// ""
	

	// string::replace  �滻�ַ�����
	string s6("012345");
	s6.replace(2, 4, "aa");			// 01aa
	s6.replace(s6.begin(), s6.end() - 1, "2");		// 2a 


	// swap()��string::swap()
	string s7("012");
	// ��ĳ�Ա����
	s7.swap(s6);	
	// ȫ��string���͵Ľ����������ڲ�����string�ĳ�Ա����swap()ʵ�ֽ���
	swap(s6, s7);	
	int a = 1, b = 2;
	// ���������������͵�ȫ�ֽ����������ײ��롰ȫ��string���͵Ľ�����������ͬ
	swap(a, b);


	// string::c_str��ֻ���ӿڣ�����const char*�������޸�
	// string::data��ͬ��
	const char* ptr1 = s7.c_str();		
	const char* ptr2 = s7.data();
	// ���ص�ַ��ͬ


	// string::find  �����ַ�����
	string s8("abcba");
	// ��������ַ�a  pos1 = 0
	size_t pos1 = s8.find("a");	
	// ��������ַ�a  pos2 = 4
	size_t pos2 = s8.rfind("a");


	// string::findӦ��ʵ��
	string file1 = "test.tar.gz.zip";
	size_t pos3 = file1.rfind(".");
	// string::substr����ȡ�ַ�����һ����
	// string::substr  ��һ����������ʼλ�� �ڶ�����������ȡ����
	// str1 = "zip"
	string str1 = file1.substr(pos3 + 1, file1.size() - pos3 - 1);
	// str2 = "zip"
	// ����Ϊ100���ж��ٿ�����
	string str2 = file1.substr(pos3 + 1, 100);


	return 0;
}
