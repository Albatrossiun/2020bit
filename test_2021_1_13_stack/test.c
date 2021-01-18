#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// ֧�ֶ�̬������ջ
typedef int STDataType;
typedef struct Stack
{
	STDataType* _a;
	int _top;		// ջ��
	int _capacity;  // ���� 
}Stack;

// ��ʼ��ջ 
void StackInit(Stack* ps)
{
	if (ps == NULL)
		return;
	ps->_top = 0;
	ps->_capacity = 0;
	ps->_a = NULL;
}

// ջ�������
void StackCheck(Stack* ps)
{
	if(ps->_top==ps->_capacity)
	{
		int newcapacity = (ps->_capacity == 0 ? 1 : 2 * ps->_capacity);
		ps->_a = (STDataType*)realloc(ps->_a, sizeof(STDataType) * newcapacity);
		ps->_capacity = newcapacity;
	}
}

// ��ջ 
void StackPush(Stack* ps, STDataType data)
{
	StackCheck(ps);
	ps->_a[ps->_top++] = data;
}

// ��ջ 
void StackPop(Stack* ps)
{
	if (ps == NULL || ps->_top == 0)
		return;
	ps->_top--;
}

// ��ȡջ��Ԫ�� 
STDataType StackTop(Stack* ps)
{
	assert(ps);
	if (ps->_top == 0)
		return (STDataType)0;
	return ps->_a[ps->_top - 1];
}

// ��ȡջ����ЧԪ�ظ��� 
int StackSize(Stack* ps)
{
	assert(ps);
	return ps->_top;
}

// ���ջ�Ƿ�Ϊ�գ����Ϊ�շ��ط������������Ϊ�շ���0 
int StackEmpty(Stack* ps)
{
	assert(ps);
	return ps->_top == 0;
}

// ����ջ 
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