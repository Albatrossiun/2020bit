#pragma once
#include <stdio.h>
#include <stdlib.h>

typedef int LDataType;

//����ڵ�
typedef struct ListNode
{
	LDataType _data;
	struct ListNode* _next;
}ListNode;

//��������
typedef struct List
{
	ListNode* _head;
}List;

//��ʼ������
void ListInit(List* lst);
//��������ڵ�
ListNode* creatListNode(LDataType val);
//β�壺O(n)
void ListPushBack(List* lst, LDataType val);
//βɾ��O(n)
void ListPopBack(List* lst);
//ͷ�壺O(1)
void ListPushFront(List* lst, LDataType val);
//ͷɾ��O(1)
void ListPopFront(List* lst);
//����������ڵ㴦����
void ListInterAfter(ListNode* node, LDataType val);
//����������ڵ㴦ɾ��
void ListErasetAfter(ListNode* node);
//���������е����ݲ����ؽڵ��ַ
ListNode* ListFind(List* lst, LDataType val);
//��������
void ListDestroy(List* lst);
//��ӡ��������
void ListPrint(List* lst);