#include <iostream>
using namespace std;

class Student
{
public:
	int add(int x, int y)
	{
		return x + y;
	}
private:
	char _name[10];
	int _age;
};

int main()
{
	cout << sizeof(Student) << " ";
	return 0;
}