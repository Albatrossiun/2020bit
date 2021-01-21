#include "list.h"

//初始化顺序表
void initseqList(seqList* sl)
{
	if (sl == NULL)
		return;
	sl->_data = NULL;
	sl->_size = 0;
	sl->_capacity = 0;
}

//检查顺序表容量
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

//打印顺序表数据
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

//查找顺序表中的数据
SLDataType seqListAt(seqList* sl, int pos)
{
	return sl->_data[pos];
}

//判断顺序表是否为空
int seqListEmpty(seqList* sl)
{
	if (sl == NULL || sl->_size == 0)
	{
		return 1;
	}
	else
		return 0;
}

//确认顺序表中的有效信息个数
int seqListSize(seqList* sl)
{
	if (sl == NULL || sl->_size == 0)
	{
		return 0;
	}
	else
		return sl->_size;
}

//对顺序表进行尾插操作
void seqListPushBack(seqList* sl, SLDataType n)
{
	if (sl == NULL)
		return;
	seqListCheckCapacity(sl);
	sl->_data[sl->_size] = n;
	sl->_size++;
}

//对顺序表进行头插操作
void seqListPushFront(seqList* sl, SLDataType n)
{
	if (sl == NULL)
		return;
	seqListCheckCapacity(sl);
	int i = sl->_size ;
	for (i ; i >0 ; i--)
	{
		sl->_data[i] = sl->_data[i - 1];
	}
	sl->_data[0] = n;
	sl->_size++;
}

//对顺序表进行头删操作
void seqListPopFront(seqList* sl)
{
	if (sl == NULL)
		return;
	int i = 1;
	for (i = 1; i < sl->_size; i++)
	{
		sl->_data[i - 1] = sl->_data[i];
	}
	sl->_size--;
}

//对顺序表进行尾删操作
void seqListPopBack(seqList* sl)
{
	if (sl == NULL)
		return;
	sl->_size--;
}

//销毁顺序表
void seqListDestory(seqList* sl)
{
	if (sl == NULL)
		return;
	free(sl->_data);
	sl->_data = NULL;
	sl->_size = 0;
	sl->_capacity = 0;
}

//在指定位置插入数据
void seqListInsert(seqList* sl, int pos, SLDataType n)
{
	if (sl == NULL)
		return;
	if (pos<0 || pos>sl->_size)
		return;
	seqListCheckCapacity(sl);
	int i = sl->_size;
	for (i; i >= pos; i--)
	{
		sl->_data[i] = sl->_data[i - 1];
	}
	sl->_data[pos] = n;
	sl->_size++;
}

//删除指定位置的数据
void seqListErase(seqList* sl, int pos)
{
	if (sl == NULL)
		return;
	if (pos<0 || pos>=sl->_size)
		return;
	int i = pos;
	for (i; i < sl->_size-1 ; i++)
	{
		sl->_data[i] = sl->_data[i + 1];
	}
	sl->_size--;
}

//顺序表头部元素
SLDataType seqListBack(seqList* sl)
{
	return sl->_data[sl->_size - 1];
}
