#include "linkedlist.h"

//��ʼ������
void ListInit(List* lst)
{
	if (lst == NULL)
		return;
	lst->_head = NULL;
}

//��������ڵ�
ListNode* creatListNode(LDataType val)
{
	ListNode* newnode = (ListNode*)malloc(sizeof(ListNode));
	newnode->_data = val;
	newnode->_next = NULL;
	return newnode;
}

//β�壺O(n)
void ListPushBack(List* lst, LDataType val)
{
	if (lst == NULL)
		return;
	ListNode* node = creatListNode(val);
	// ������������Ϊ��
	if (lst->_head == NULL)
		lst->_head = node;
	// ����Ϊ��
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

//βɾ��O(n)
void ListPopBack(List* lst)
{
	if (lst == NULL || lst->_head == NULL)
		return;
	// ��¼�������ڶ����ڵ�
	ListNode* prev = NULL;
	// ��¼����β�ڵ�
	ListNode* tail = lst->_head;
	// ��ȡ���һ���ڵ�
	while (tail->_next)
	{
		prev = tail;
		tail = tail->_next;
	}
	free(tail);
	// ����ֻ��һ���ڵ㣬ɾ��������Ϊ��
	if (prev == NULL)
		lst->_head = NULL;
	else
		prev->_next = NULL;
}

//ͷ�壺O(1)
void ListPushFront(List* lst, LDataType val)
{
	if (lst == NULL)
		return;
	ListNode* node = creatListNode(val);
	node->_next = lst->_head;
	lst->_head = node;
}

//ͷɾ��O(1)
void ListPopFront(List* lst)
{
	if (lst == NULL || lst->_head == NULL)
		return;
	ListNode* next = lst->_head->_next;
	free(lst->_head);
	lst->_head = next;
}

//����������ڵ㴦����
void ListInterAfter(ListNode* node, LDataType val)
{
	if (node == NULL)
		return;
	ListNode* newNode = creatListNode(val);
	newNode->_next = node->_next;
	node->_next = newNode;
}

//����������ڵ㴦ɾ��
void ListErasetAfter(ListNode* node)
{
	if (node == NULL || node->_next == NULL)
		return;
	ListNode* next = node->_next->_next;
	free(node->_next);
	node->_next = next;
}

//���������е����ݲ����ؽڵ��ַ
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

//��������
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

//��ӡ��������
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

//���Ժ���
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

//������
int main()
{
	test();
	return 0;
}