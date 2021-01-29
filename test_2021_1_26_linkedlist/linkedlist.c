#include "linkedlist.h"

//初始化链表
void ListInit(List* lst)
{
	if (lst == NULL)
		return;
	lst->_head = NULL;
}

//创建链表节点
ListNode* creatListNode(LDataType val)
{
	ListNode* newnode = (ListNode*)malloc(sizeof(ListNode));
	newnode->_data = val;
	newnode->_next = NULL;
	return newnode;
}

//尾插：O(n)
void ListPushBack(List* lst, LDataType val)
{
	if (lst == NULL)
		return;
	ListNode* node = creatListNode(val);
	// 如果链表存在且为空
	if (lst->_head == NULL)
		lst->_head = node;
	// 链表不为空
	else
	{
		ListNode* tail = lst->_head;
		while (tail->_next)
		{
			tail = tail->_next;
		}
		tail->_next = node;
	}
}

//尾删：O(n)
void ListPopBack(List* lst)
{
	if (lst == NULL || lst->_head == NULL)
		return;
	// 记录链表倒数第二个节点
	ListNode* prev = NULL;
	// 记录链表尾节点
	ListNode* tail = lst->_head;
	// 获取最后一个节点
	while (tail->_next)
	{
		prev = tail;
		tail = tail->_next;
	}
	free(tail);
	// 链表只有一个节点，删除后链表为空
	if (prev == NULL)
		lst->_head = NULL;
	else
		prev->_next = NULL;
}

//头插：O(1)
void ListPushFront(List* lst, LDataType val)
{
	if (lst == NULL)
		return;
	ListNode* node = creatListNode(val);
	node->_next = lst->_head;
	lst->_head = node;
}

//头删：O(1)
void ListPopFront(List* lst)
{
	if (lst == NULL || lst->_head == NULL)
		return;
	ListNode* next = lst->_head->_next;
	free(lst->_head);
	lst->_head = next;
}

//从链表任意节点处插入
void ListInterAfter(ListNode* node, LDataType val)
{
	if (node == NULL)
		return;
	ListNode* newNode = creatListNode(val);
	newNode->_next = node->_next;
	node->_next = newNode;
}

//从链表任意节点处删除
void ListErasetAfter(ListNode* node)
{
	if (node == NULL || node->_next == NULL)
		return;
	ListNode* next = node->_next->_next;
	free(node->_next);
	node->_next = next;
}

//查找链表中的数据并返回节点地址
ListNode* ListFind(List* lst, LDataType val)
{
	if (lst == NULL || lst->_head == NULL)
		return;
	ListNode* cur = lst->_head;
	while (cur)
	{
		if (cur->_data == val)
		{
			return cur;
		}
		cur = cur->_next;
	}
	return NULL;
}

//销毁链表
void ListDestroy(List* lst)
{
	if (lst == NULL)
		return;
	ListNode* cur = lst->_head;
	while (cur)
	{
		ListNode* next = cur->_next;
		free(cur);
		cur = next;
	}
	lst->_head = NULL;
}

//打印链表数据
void ListPrint(List* lst)
{
	if (lst == NULL || lst->_head == NULL)
		return;
	ListNode* cur = lst->_head;
	while (cur)
	{
		printf("%d ", cur->_data);
		cur = cur->_next;
	}
	printf("\n");
}

//测试函数
void test()
{
	List sl;
	ListInit(&sl);
	ListPushBack(&sl, 2); // 2
	ListPushBack(&sl, 3); // 2 3
	ListPushBack(&sl, 4); // 2 3 4
	ListPushFront(&sl, 1); // 1 2 3 4
	ListPopFront(&sl); // 2 3 4
	ListPopBack(&sl); // 2 3
	ListInterAfter((sl._head->_next), 4); // 2 3 4
	ListErasetAfter((sl._head)); // 2 4
	ListPrint(&sl);
	//ListNode* new = ListFind(&sl, 4);
	//printf("%d\n", new->_data);
}

//主函数
int main()
{
	test();
	return 0;
}