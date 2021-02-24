#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
#include <vector>
using namespace std;


// vector������ʽ������
void test1()
{
	string s1 = "012345";
	// end()ȡ����_str[_size]
	// ����v1����û��'\0'
	// 1.���������
	vector<char> v1(s1.begin(), s1.end());
	vector<char>::iterator it = v1.begin();
	// �ɶ���д�ӿ�
	while (it != v1.end())
	{
		cout << *it << " ";
		it++;
	}
	// 1.���������
	vector<char>::reverse_iterator rit = v1.rbegin();
	// �ɶ���д�ӿ�
	while (rit != v1.rend())
	{
		cout << *rit << " ";
		rit++;
	}


	// 2.��Χfor
	for (auto& ch : v1)
	{
		cout << ch << " ";
	}

	// 3.operator[]
	for (int i = 0; i < v1.size(); i++)
	{
		cout << v1[i] << " ";
	}
}


// printVec() ��ӡ����
template <class T>
void printVec(const vector<T>& v)
{
	// ������� ֻ��
	typename vector<T>::const_iterator it = v.cbegin();
	while (it != v.cend())
	{
		cout << *it << " ";
		it++;
	}

	// ������� ֻ��
	typename vector<T>::const_reverse_iterator rit = v.crbegin();
	while (rit != v.crend())
	{
		cout << *rit << " ";
		rit++;
	}
}


// printVec() ��ӡ����Ӧ��ʵ��
// ����vector
void test2()
{
	int a[5] = { 1,2,3,4,5 };
	vector<int> v(a, a + 5);
	printVec(v);

	char a2[6] = "asdfg";
	vector<char> v2(a2, a2 + 6);
	printVec(v2);

	string a3[2] = { "qqq","www" };
	vector<string> v3(a3, a3 + 2);
	printVec(v3);
}


// vector ��ʼ����
// ��string��ʼ����15��ͬ
// vector ���Ϊ�գ���ʼ����Ϊ0
// PJ�������ݰ��մ���1.5������
void test3()
{
	vector<int> v;
	size_t size = v.size();
	size_t cap = v.capacity();
	cout << cap << endl;
	for (int i = 0; i < 200; i++)
	{
		v.push_back(i);
		if (cap != v.capacity())
		{
			cap = v.capacity();
			cout << cap << endl;
		}
	}
}


// vector::front() ��ȡ��һ��Ԫ��
// vector::back() ��ȡ���һ��Ԫ��
void test4()
{
	int a[5] = { 1,2,3,4,5 };
	vector<int> v(a, a + 5);
	int v1 = v.front();
	int v2 = v.back();
}


// vector::insert()
// ���������������ǰһ��λ��
// ����Ĳ�����Ҫʹ�õ�����
void test5()
{
	vector<int> v;
	int a[] = { 1,2,3,4,5 };
	v.insert(v.begin(), 8);			// 8
	// v.end()�����һ��Ԫ�ص���һλ
	v.insert(v.end(), 2, 9);		// 899
	// ����a�ĵ������ǡ�����ҿ���
	v.insert(v.begin(), a + 1, a + 3);		// 23899
}


bool isMatch(char* s, char* p)
{
	int m = 5;
	int n = 4;
	int dp[6][5];
	memset(dp, 0, sizeof(dp));
	dp[0][0] = true;
	for (int i = 1; i <= n; i++)
	{
		if (p[i - 1] == '*')
			dp[0][i] = true;
		else
			break;
	}
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (p[j - 1] == '*')
				dp[i][j] = dp[i][j - 1] | dp[i - 1][j];
			else if (p[j - 1] == '?' || s[i - 1] == p[j - 1])
				dp[i][j] = dp[i - 1][j - 1];
		}
	}
	return dp[m][n];
}

int main()
{
	char s[] = "acdcb";
	char p[] = "a*cb";
	int a = isMatch(s, p);
	cout << a;

	return 0;
}
