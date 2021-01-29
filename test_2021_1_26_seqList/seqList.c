#include "seqList.h"

void SeqListInit(SeqList* ps)
{
	if (ps == NULL)
		return;
	ps->a = NULL;
	ps->capacity = 0;
	ps->size = 0;
}

void SeqListDestory(SeqList* ps)
{
	if (ps == NULL)
		return;
	free(ps->a);
	ps->a = NULL;
	ps->capacity = 0;
	ps->size = 0;
}

void SeqListPrint(SeqList* ps)
{
	if (ps == NULL)
		return;
	int i;
	for (i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->a[i]);
	}
	printf("\n");
}

// 检查顺序表容量
void seqListCheckCapacity(SeqList* ps)
{
	if (ps == NULL)
		return;
	if (ps->size == ps->capacity)
	{
		int new = ps->capacity == 0 ? 1 : 2 * ps->capacity;
		ps->a = (SLDateType*)realloc(ps->a, sizeof(SLDateType) * new);
		ps->capacity = new;
	}
	//if (ps->_size == ps->_capacity)
	//{
	//	int newCapacity = (ps->_capacity == 0 ? 1 : 2 * (ps->_capacity));
	//	SLDataType* tmp = (SLDataType*)malloc(newCapacity * sizeof(SLDataType));
	//	memcpy(tmp, ps->_data, sizeof(SLDataType) * ps->_size);
	//	free(ps->_data);
	//	ps->_data = tmp;
	//	ps->_capacity = newCapacity;
	//}
}

// 顺序表尾插
void SeqListPushBack(SeqList* ps, SLDateType x)
{
	if (ps == NULL)
		return;
	seqListCheckCapacity(ps);
	ps->a[ps->size++] = x;
}

// 顺序表头插
void SeqListPushFront(SeqList* ps, SLDateType x)
{
	if (ps == NULL)
		return;
	seqListCheckCapacity(ps);
	int i = ps->size;
	for (i; i > 0; i--)
	{
		ps->a[i] = ps->a[i - 1];
	}
	ps->a[0] = x;
	ps->size++;
}

// 顺序表头删
void SeqListPopFront(SeqList* ps)
{
	if (ps == NULL)
		return;
	int i = 1;
	for (i; i < ps->size; i++)
	{
		ps->a[i - 1] = ps->a[i];
	}
	ps->size--;
}

// 顺序表尾删
void SeqListPopBack(SeqList* ps)
{
	if (ps == NULL)
		return;
	ps->size--;
}

// 顺序表查找
int SeqListFind(SeqList* ps, SLDateType x)
{
	if (ps == NULL)
		return;
	int i;
	for (i = 0; i < ps->size; i++)
	{
		if (ps->a[i] == x)
			return i;
	}
	return -1;
}

// 顺序表在pos位置插入x
void SeqListInsert(SeqList* ps, size_t pos, SLDateType x)
{
	if (ps == NULL)
		return;
	seqListCheckCapacity(ps);
	int i;
	for (i = ps->size; i >= pos; i--)
	{
		ps->a[i] = ps->a[i - 1];
	}
	ps->a[pos] = x;
	ps->size++;
}

// 顺序表删除pos位置的值
void SeqListErase(SeqList* ps, size_t pos)
{
	if (ps == NULL)
		return;
	if (pos < 0 || pos >= ps->size)
		return;
	int i = pos;
	for (i; i < ps->size-1 ; i++)
	{
		ps->a[i] = ps->a[i + 1];
	}
	ps->size--;
}

void test()
{
	SeqList sq;
	SeqListInit(&sq);
	SeqListPushBack(&sq, 3);
	SeqListPushBack(&sq, 4);
	SeqListPushBack(&sq, 5);
	SeqListPushFront(&sq, 2);
	SeqListPushFront(&sq, 1);
	SeqListPushFront(&sq, 0);
	SeqListPopBack(&sq);
	SeqListPopFront(&sq);
	SeqListInsert(&sq, 3, 100);
	SeqListErase(&sq, 3);
	SeqListPrint(&sq);
}

int main()
{
	test();
	return 0;
}