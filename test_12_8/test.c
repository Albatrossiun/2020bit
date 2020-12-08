#include <stdio.h>


typedef int LDataType;

//定义节点
typedef struct listNode 
{
	LDataType _data;
	struct listNode* _next;
}listNode;

//定义链表
typedef struct list
{
	listNode* _head;
}list;

//初始化链表
void listInit(list* lst)
{
	if (lst == NULL)
	{
		return;
	}
	lst->_head = NULL;
}

//创建链表节点
listNode* creatListNode(LDataType val)
{
	listNode* node = (listNode*)malloc(sizeof(listNode));
	node->_data = val;
	node->_next = NULL;
	return node;
}

//尾插：O(n)
void listPushBack(list* lst, LDataType val)
{
	if (lst == NULL)
		return;
	if (lst->_head == NULL)
	{
		lst->_head = creatListNode(val);
	}
	else
	{
		listNode* tail = lst->_head;
		while (tail->_next)
		{
			tail = tail->_next;
		}
		tail->_next = creatListNode(val);
	}
}

//尾删：O(n)
void listPopBack(list* lst)
{
	if (lst == NULL || lst->_head == NULL)
		return;
	listNode* prev = NULL;
	listNode* tail = lst->_head;
	while (tail->_next)
	{
		prev = tail;
		tail = tail->_next;
	}
	free(tail);
	if (prev == NULL)
	{
		lst->_head == NULL;
	}
	else
	{
		prev->_next = NULL;
	}
}

//头插：O(1)
void listPushFront(list* lst, LDataType val)
{
	if (lst == NULL)
		return;
	listNode* node = creatListNode(val);
	node->_next = lst->_head;
	lst->_head = node;
}

//头删：O(1)
void listPopFront(list* lst)
{
	if (lst == NULL || lst->_head == NULL)
		return;
	listNode* next = lst->_head->_next;
	free(lst->_head);
	lst->_head = next;
}

//从链表任意节点处插入
void listInterAfter(listNode* node, LDataType val)
{
	if (node == NULL)
		return;
	listNode* newNode = creatListNode(val);
	newNode->_next = node->_next;
	node->_next = newNode;
}


//从链表任意节点处删除
void listErasetAfter(listNode* node)
{
	if (node == NULL || node->_next == NULL)
		return;
	listNode* next = node->_next->_next;
	free(node->_next);
	node->_next = next;
}

//查找链表中的数据并返回节点地址
listNode* listFind(list* lst, LDataType val)
{
	if (lst == NULL || lst->_head == NULL)
		return;
	listNode* cur = lst->_head;
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
void listDestroy(list* lst)
{
	if (lst == NULL)
		return;
	listNode* cur = lst->_head;
	while (cur)
	{
		listNode* next = cur->_next;
		free(cur);
		cur = next;
	}
	lst->_head = NULL;
}

//测试函数
void test()
{
	list sl;
	listInit(&sl);
	listPushBack(&sl, 3);
	listPushBack(&sl, 2);
	listPushBack(&sl, 1);
	listPushFront(&sl, 0);
	listPopFront(&sl);
	listPopBack(&sl);
	listInterAfter((sl._head->_next), 5);
	listErasetAfter((sl._head));
	listNode* new = listFind(&sl, 3);
	printf("%d\n", new->_next->_data);
}

//主函数
int main()
{
	test();
	return 0;
}