#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// 支持动态增长的栈
typedef int STDataType;
typedef struct Stack
{
	STDataType* _a;
	int _top;		// 栈顶
	int _capacity;  // 容量 
}Stack;

// 初始化栈 
void StackInit(Stack* ps)
{
	if (ps == NULL)
		return;
	ps->_top = 0;
	ps->_capacity = 0;
	ps->_a = NULL;
}

// 栈容量检测
void StackCheck(Stack* ps)
{
	if(ps->_top==ps->_capacity)
	{
		int newcapacity = (ps->_capacity == 0 ? 1 : 2 * ps->_capacity);
		ps->_a = (STDataType*)realloc(ps->_a, sizeof(STDataType) * newcapacity);
		ps->_capacity = newcapacity;
	}
}

// 入栈 
void StackPush(Stack* ps, STDataType data)
{
	StackCheck(ps);
	ps->_a[ps->_top++] = data;
}

// 出栈 
void StackPop(Stack* ps)
{
	if (ps == NULL || ps->_top == 0)
		return;
	ps->_top--;
}

// 获取栈顶元素 
STDataType StackTop(Stack* ps)
{
	assert(ps);
	if (ps->_top == 0)
		return (STDataType)0;
	return ps->_a[ps->_top - 1];
}

// 获取栈中有效元素个数 
int StackSize(Stack* ps)
{
	assert(ps);
	return ps->_top;
}

// 检测栈是否为空，如果为空返回非零结果，如果不为空返回0 
int StackEmpty(Stack* ps)
{
	assert(ps);
	return ps->_top == 0;
}

// 销毁栈 
void StackDestroy(Stack* ps)
{
	if (ps == NULL)
		return;
	if (ps->_a)
	{
		free(ps->_a);
		ps->_a = NULL;
		ps->_capacity = 0;
		ps->_top = 0;
	}
}

void test()
{

	Stack ps;
	StackInit(&ps);
	StackPush(&ps, 2);
	StackPush(&ps, 4);
	StackPush(&ps, 6);
	StackPush(&ps, 8);
	StackPop(&ps);
	StackPop(&ps);
	STDataType element = StackTop(&ps);
	printf("get the top element:%d\n", element);
	int count = StackSize(&ps);
	printf("count:%d\n", count);
	int empty = StackEmpty(&ps);
	printf("empty:%d\n", empty);
}

int main()
{
	test();
	return 0;
}