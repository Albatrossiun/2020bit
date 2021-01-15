#include <stdio.h>
// ��ͷ+˫��+ѭ��������ɾ���ʵ��
typedef int LTDataType;

typedef struct ListNode
{
	LTDataType _data;
	struct ListNode* _next;
	struct ListNode* _prev;
}ListNode;

// �������������ͷ���.
ListNode* ListCreate()
{
	ListNode* _head = (ListNode*)malloc(sizeof(ListNode));
	_head->_next = _head;
	_head->_prev = _head;
	return _head;
}

// ˫����������
void ListDestory(ListNode* pHead)
{
	if (pHead==NULL)
		return;
	ListNode* cur = pHead->_next;
	while (cur != pHead)
	{
		ListNode* next = cur->_next;
		free(cur);
		cur = next;
	}
	free(pHead);
	pHead = NULL;
}

// ˫�������ӡ
void ListPrint(ListNode* pHead)
{
	if (pHead==NULL)
		return;
	ListNode* cur = pHead->_next;
	while (cur != pHead)
	{
		printf("%d ", cur->_data);
		cur = cur->_next;
	}
	printf("\n");
}

// ˫������β��
void ListPushBack(ListNode* pHead, LTDataType x)
{
	ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
	newNode->_data = x;

	ListNode* tail = pHead->_prev;

	tail->_next = newNode;
	newNode->_prev = tail;
	newNode->_next = pHead;
	pHead->_prev = newNode;
}

// ˫������βɾ
void ListPopBack(ListNode* pHead)
{
	if (pHead == NULL || pHead->_next == pHead)
		return;
	ListNode* prev = pHead->_prev->_prev;
	free(pHead->_prev);
	pHead->_prev = prev;
	prev->_next = pHead;
}

// ˫������ͷ��
void ListPushFront(ListNode* pHead, LTDataType x)
{
	if (pHead == NULL)
		return;
	ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
	newNode->_data = x;

	newNode->_prev = pHead;
	newNode->_next = pHead->_next;
	pHead->_next->_prev = newNode;
	pHead->_next = newNode;
}

// ˫������ͷɾ
void ListPopFront(ListNode* pHead)
{
	if (pHead == NULL || pHead->_next == pHead)
		return;
	ListNode* first = pHead->_next;
	first->_next->_prev = pHead;
	pHead->_next = first->_next;
	free(first);
}

// ˫���������
ListNode* ListFind(ListNode* pHead, LTDataType x)
{
	if (pHead == NULL)
		return;
	ListNode* cur = pHead->_next;
	while (cur != pHead)
	{
		ListNode* next = cur->_next;
		if (cur->_data == x)
			return cur;
		cur = next;
	}
}

// ˫��������pos��ǰ����в���
void ListInsert(ListNode* pos, LTDataType x)
{
	ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
	newNode->_data = x;

	newNode->_next = pos;
	newNode->_prev = pos->_prev;
	pos->_prev->_next = newNode;
	pos->_prev = newNode;
}

// ˫������ɾ��posλ�õĽڵ�
void ListErase(ListNode* pos)
{
	if (pos == NULL)
		return;
	ListNode* prev = pos->_prev;
	prev->_next = pos->_next;
	pos->_next->_prev = prev;
	free(pos);
}

int main()
{
	ListNode* pHead = ListCreate();
	ListPushBack(pHead, 1);
	ListPrint(pHead);
	ListPushBack(pHead, 2);
	ListPrint(pHead);
	ListPushBack(pHead, 3);
	ListPrint(pHead);
	ListPopBack(pHead);
	ListPrint(pHead);
	ListPopBack(pHead);
	ListPrint(pHead);
	ListPushFront(pHead, 0);
	ListPrint(pHead);
	ListPushFront(pHead, 1);
	ListPrint(pHead);
	ListPushFront(pHead, 2);
	ListPrint(pHead);
	ListPopFront(pHead);
	ListPrint(pHead);
	ListPopFront(pHead);
	ListPopFront(pHead);
	ListPrint(pHead);
	return 0;
}