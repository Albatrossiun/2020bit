#include "test.h"

void initseqList(seqList* sl)
{
	if (sl == NULL)
		return;
	sl->_data = NULL;
	sl->_size = 0;
	sl->_capacity = 0;
}

void seqListCheckCapacity(seqList* sl)
{
	if (sl == NULL)
		return;
	if (sl->_size == sl->_capacity)
	{
		int newCapacity = (sl->_capacity == 0 ? 1 : 2 * (sl->_capacity));
		SLDataType* tmp = (SLDataType*)malloc(newCapacity * sizeof(SLDataType));
		memcpy(tmp, sl->_data, sizeof(SLDataType) * sl->_size);
		free(sl->_data);
		sl->_data = tmp;
		sl->_capacity = newCapacity;
	}
}

void seqListPrint(seqList* sl)
{
	if (sl == NULL)
		return;
	int i;
	for (i = 0; i < sl->_size; i++)
	{
		printf("%d", sl->_data[i]);
	}
	printf("\n");
}

SLDataType seqListAt(seqList* sl, int pos)
{
	return sl->_data[pos];
}

int seqListEmpty(seqList* sl)
{
	if (sl == NULL || sl->_size == 0)
	{
		return 0;
	}
	else
		return 1;
}

int seqListSize(seqList* sl)
{
	if (sl == NULL || sl->_size == 0)
	{
		return 0;
	}
	else
		return sl->_size;
}

void seqListPushBack(seqList* sl, SLDataType n)
{
	if (sl == NULL)
		return;
	seqListCheckCapacity(sl);
	sl->_data[sl->_size] = n;
	sl->_size++;
}

void test()
{
	seqList sl = { 0 };
	seqListPushBack(&sl, 1);
	seqListPushBack(&sl, 2);
	seqListPushBack(&sl, 3);
	seqListPushBack(&sl, 4);
	seqListPushBack(&sl, 5);
	seqListPrint(&sl);
}

int main()
{
	test();
	return 0;
}