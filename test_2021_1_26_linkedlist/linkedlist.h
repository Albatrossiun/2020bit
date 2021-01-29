#pragma once
#include <stdio.h>
#include <stdlib.h>

typedef int LDataType;

//定义节点
typedef struct ListNode
{
	LDataType _data;
	struct ListNode* _next;
}ListNode;

//定义链表
typedef struct List
{
	ListNode* _head;
}List;

//初始化链表
void ListInit(List* lst);
//创建链表节点
ListNode* creatListNode(LDataType val);
//尾插：O(n)
void ListPushBack(List* lst, LDataType val);
//尾删：O(n)
void ListPopBack(List* lst);
//头插：O(1)
void ListPushFront(List* lst, LDataType val);
//头删：O(1)
void ListPopFront(List* lst);
//从链表任意节点处插入
void ListInterAfter(ListNode* node, LDataType val);
//从链表任意节点处删除
void ListErasetAfter(ListNode* node);
//查找链表中的数据并返回节点地址
ListNode* ListFind(List* lst, LDataType val);
//销毁链表
void ListDestroy(List* lst);
//打印链表数据
void ListPrint(List* lst);