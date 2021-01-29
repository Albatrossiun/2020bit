#pragma once
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

typedef int SLDateType;
typedef struct SeqList
{
	SLDateType* a;
	int size;
	int capacity;
}SeqList;

// 顺序表初始化
void SeqListInit(SeqList* ps);
// 顺序表销毁
void SeqListDestory(SeqList* ps);
// 顺序表打印
void SeqListPrint(SeqList* ps);
// 尾插
void SeqListPushBack(SeqList* ps, SLDateType x);
// 头插
void SeqListPushFront(SeqList* ps, SLDateType x);
// 头删
void SeqListPopFront(SeqList* ps);
// 尾删
void SeqListPopBack(SeqList* ps);
// 顺序表查找
int SeqListFind(SeqList* ps, SLDateType x);
// 顺序表在pos位置插入x
void SeqListInsert(SeqList* ps, size_t pos, SLDateType x);
// 顺序表删除pos位置的值
void SeqListErase(SeqList* ps, size_t pos);
