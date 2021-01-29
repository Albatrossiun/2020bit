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

// ˳����ʼ��
void SeqListInit(SeqList* ps);
// ˳�������
void SeqListDestory(SeqList* ps);
// ˳����ӡ
void SeqListPrint(SeqList* ps);
// β��
void SeqListPushBack(SeqList* ps, SLDateType x);
// ͷ��
void SeqListPushFront(SeqList* ps, SLDateType x);
// ͷɾ
void SeqListPopFront(SeqList* ps);
// βɾ
void SeqListPopBack(SeqList* ps);
// ˳������
int SeqListFind(SeqList* ps, SLDateType x);
// ˳�����posλ�ò���x
void SeqListInsert(SeqList* ps, size_t pos, SLDateType x);
// ˳���ɾ��posλ�õ�ֵ
void SeqListErase(SeqList* ps, size_t pos);
