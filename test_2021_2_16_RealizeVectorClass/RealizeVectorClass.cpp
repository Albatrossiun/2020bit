#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
#include <vector>
using namespace std;


// vector遍历方式：三种
void test1()
{
	string s1 = "012345";
	// end()取不到_str[_size]
	// 所以v1里面没有'\0'
	// 1.正向迭代器
	vector<char> v1(s1.begin(), s1.end());
	vector<char>::iterator it = v1.begin();
	// 可读可写接口
	while (it != v1.end())
	{
		cout << *it << " ";
		it++;
	}
	// 1.反向迭代器
	vector<char>::reverse_iterator rit = v1.rbegin();
	// 可读可写接口
	while (rit != v1.rend())
	{
		cout << *rit << " ";
		rit++;
	}


	// 2.范围for
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


// printVec() 打印函数
template <class T>
void printVec(const vector<T>& v)
{
	// 正向遍历 只读
	typename vector<T>::const_iterator it = v.cbegin();
	while (it != v.cend())
	{
		cout << *it << " ";
		it++;
	}

	// 反向遍历 只读
	typename vector<T>::const_reverse_iterator rit = v.crbegin();
	while (rit != v.crend())
	{
		cout << *rit << " ";
		rit++;
	}
}


// printVec() 打印函数应用实例
// 创建vector
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


// vector 初始容量
// 与string初始容量15不同
// vector 如果为空，初始容量为0
// PJ版中增容按照大于1.5倍进行
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


// vector::front() 获取第一个元素
// vector::back() 获取最后一个元素
void test4()
{
	int a[5] = { 1,2,3,4,5 };
	vector<int> v(a, a + 5);
	int v1 = v.front();
	int v2 = v.back();
}


// vector::insert()
// 插入给定迭代器的前一个位置
// 这里的参数均要使用迭代器
void test5()
{
	vector<int> v;
	int a[] = { 1,2,3,4,5 };
	v.insert(v.begin(), 8);			// 8
	// v.end()是最后一个元素的下一位
	v.insert(v.end(), 2, 9);		// 899
	// 这里a的迭代器是“左闭右开”
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
