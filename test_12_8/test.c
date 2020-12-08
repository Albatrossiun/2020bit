#include <stdio.h>


typedef int LDataType;

//����ڵ�
typedef struct listNode 
{
	LDataType _data;
	struct listNode* _next;
}listNode;

//��������
typedef struct list
{
	listNode* _head;
}list;

//��ʼ������
void listInit(list* lst)
{
	if (lst == NULL)
	{
		return;
	}
	lst->_head = NULL;
}

//��������ڵ�
listNode* creatListNode(LDataType val)
{
	listNode* node = (listNode*)malloc(sizeof(listNode));
	node->_data = val;
	node->_next = NULL;
	return node;
}

//β�壺O(n)
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

//βɾ��O(n)
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

//ͷ�壺O(1)
void listPushFront(list* lst, LDataType val)
{
	if (lst == NULL)
		return;
	listNode* node = creatListNode(val);
	node->_next = lst->_head;
	lst->_head = node;
}

//ͷɾ��O(1)
void listPopFront(list* lst)
{
	if (lst == NULL || lst->_head == NULL)
		return;
	listNode* next = lst->_head->_next;
	free(lst->_head);
	lst->_head = next;
}

//����������ڵ㴦����
void listInterAfter(listNode* node, LDataType val)
{
	if (node == NULL)
		return;
	listNode* newNode = creatListNode(val);
	newNode->_next = node->_next;
	node->_next = newNode;
}


//����������ڵ㴦ɾ��
void listErasetAfter(listNode* node)
{
	if (node == NULL || node->_next == NULL)
		return;
	listNode* next = node->_next->_next;
	free(node->_next);
	node->_next = next;
}

//���������е����ݲ����ؽڵ��ַ
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

//��������
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

//���Ժ���
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

//������
int main()
{
	test();
	return 0;
}