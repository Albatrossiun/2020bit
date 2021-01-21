#include "list.h"

//��ʼ��˳���
void initseqList(seqList* sl)
{
	if (sl == NULL)
		return;
	sl->_data = NULL;
	sl->_size = 0;
	sl->_capacity = 0;
}

//���˳�������
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

//��ӡ˳�������
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

//����˳����е�����
SLDataType seqListAt(seqList* sl, int pos)
{
	return sl->_data[pos];
}

//�ж�˳����Ƿ�Ϊ��
int seqListEmpty(seqList* sl)
{
	if (sl == NULL || sl->_size == 0)
	{
		return 1;
	}
	else
		return 0;
}

//ȷ��˳����е���Ч��Ϣ����
int seqListSize(seqList* sl)
{
	if (sl == NULL || sl->_size == 0)
	{
		return 0;
	}
	else
		return sl->_size;
}

//��˳������β�����
void seqListPushBack(seqList* sl, SLDataType n)
{
	if (sl == NULL)
		return;
	seqListCheckCapacity(sl);
	sl->_data[sl->_size] = n;
	sl->_size++;
}

//��˳������ͷ�����
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

//��˳������ͷɾ����
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

//��˳������βɾ����
void seqListPopBack(seqList* sl)
{
	if (sl == NULL)
		return;
	sl->_size--;
}

//����˳���
void seqListDestory(seqList* sl)
{
	if (sl == NULL)
		return;
	free(sl->_data);
	sl->_data = NULL;
	sl->_size = 0;
	sl->_capacity = 0;
}

//��ָ��λ�ò�������
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

//ɾ��ָ��λ�õ�����
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

//˳���ͷ��Ԫ��
SLDataType seqListBack(seqList* sl)
{
	return sl->_data[sl->_size - 1];
}
