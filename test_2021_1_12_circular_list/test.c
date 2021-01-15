#include <stdio.h>
// 带头+双向+循环链表增删查改实现
typedef int LTDataType;

typedef struct ListNode
{
	LTDataType _data;
	struct ListNode* _next;
	struct ListNode* _prev;
}ListNode;

// 创建返回链表的头结点.
ListNode* ListCreate()
{
	ListNode* _head = (ListNode*)malloc(sizeof(ListNode));
	_head->_next = _head;
	_head->_prev = _head;
	return _head;
}

// 双向链表销毁
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

// 双向链表打印
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

// 双向链表尾插
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

// 双向链表尾删
void ListPopBack(ListNode* pHead)
{
	if (pHead == NULL || pHead->_next == pHead)
		return;
	ListNode* prev = pHead->_prev->_prev;
	free(pHead->_prev);
	pHead->_prev = prev;
	prev->_next = pHead;
}

// 双向链表头插
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

// 双向链表头删
void ListPopFront(ListNode* pHead)
{
	if (pHead == NULL || pHead->_next == pHead)
		return;
	ListNode* first = pHead->_next;
	first->_next->_prev = pHead;
	pHead->_next = first->_next;
	free(first);
}

// 双向链表查找
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

// 双向链表在pos的前面进行插入
void ListInsert(ListNode* pos, LTDataType x)
{
	ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
	newNode->_data = x;

	newNode->_next = pos;
	newNode->_prev = pos->_prev;
	pos->_prev->_next = newNode;
	pos->_prev = newNode;
}

// 双向链表删除pos位置的节点
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