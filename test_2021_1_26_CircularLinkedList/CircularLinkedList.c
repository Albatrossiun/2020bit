#include "CircularLinkedList.h"

// ��������ͷ���.
ListNode* ListCreate()
{
	ListNode* _head = (ListNode*)malloc(sizeof(ListNode));
	_head->_next = _head;
	_head->_prev = _head;
	return _head;
}

// �����������ݽ��.
ListNode* ListCreateNode(LTDataType x)
{
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->_next = NULL;
	node->_prev = NULL;
	node->_data = x;
	return node;
}

// ˫����������
void ListDestory(ListNode* pHead)
{
	if (pHead == NULL)
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
	if (pHead == NULL)
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
	if (pHead == NULL)
		return;
	ListNode* node = ListCreateNode(x);
	ListNode* tail = pHead->_prev;
	node->_next = pHead;
	node->_prev = tail;
	tail->_next = node;
	pHead->_prev = node;
}

// ˫������βɾ
void ListPopBack(ListNode* pHead)
{
	if (pHead == NULL || pHead->_next == pHead)
		return;
	ListNode* prev = pHead->_prev->_prev;
	free(pHead->_prev);
	prev->_next = pHead;
	pHead->_prev = prev;
}

// ˫������ͷ��
void ListPushFront(ListNode* pHead, LTDataType x)
{
	if (pHead == NULL)
		return;
	ListNode* node = ListCreateNode(x);
	pHead->_next->_prev = node;
	node->_next = pHead->_next;
	node->_prev = pHead;
	pHead->_next = node;
}

// ˫������ͷɾ
void ListPopFront(ListNode* pHead)
{
	if (pHead == NULL || pHead->_next == pHead)
		return;
	ListNode* next = pHead->_next->_next;
	free(pHead->_next);
	pHead->_next = next;
	next->_prev = pHead;
}

// ˫���������
ListNode* ListFind(ListNode* pHead, LTDataType x)
{
	if (pHead == NULL || pHead->_next == pHead)
		return NULL;
	ListNode* cur = pHead->_next;
	while (cur != pHead)
	{
		if (cur->_data == x)
			return cur;
		cur = cur->_next;
	}
}

// ˫��������pos��ǰ����в���
void ListInsert(ListNode* pos, LTDataType x)
{
	if (pos == NULL)
		return;
	ListNode* node = ListCreateNode(x);
	ListNode* prev = pos->_prev;
	node->_prev = prev;
	node->_next = pos;
	pos->_prev = node;
	prev->_next = node;
}

// ˫������ɾ��posλ�õĽڵ�
void ListErase(ListNode* pos)
{
	if (pos == NULL)
		return;
	ListNode* next = pos->_next;
	pos->_prev->_next = next;
	next->_prev = pos->_prev;
	free(pos);
}

// ���Ժ���
void test()
{
	ListNode* pHead = ListCreate();
	ListInsert(pHead, 0); // 0
	ListPushFront(pHead, 0); // 0 0
	ListPushBack(pHead, 1); // 0 0 1
	ListErase(pHead->_next); // 0 1
	ListPushBack(pHead, 2); // 0 1 2
	ListPushBack(pHead, 3); // 0 1 2 3
	ListPopFront(pHead); // 1 2 3
	ListPopBack(pHead); // 1 2
	ListPrint(pHead);
}

int main()
{
	test();
	return 0;
}