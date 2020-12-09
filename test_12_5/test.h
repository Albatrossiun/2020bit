#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <assert.h>
#include <string.h>

typedef int SLDataType;

#define N 100
typedef struct seqList2	//	��̬˳���,sizeof(seqList2)=404byte
{
	SLDataType _data[N];
	int _size;
}seqList2;

typedef struct seqList	//	��̬˳���,sizeof(seqList)=12byte
{
	SLDataType* _data;
	int _size;
	int _capacity;
}seqList;

//��ʼ��˳���
void initseqList(seqList* sl);
//��˳������β�����
void seqListPushBack(seqList* sl, SLDataType n);
//���˳�������
void seqListCheckCapacity(seqList* sl);
//��ӡ˳�������
void seqListPrint(seqList* sl);
//����˳����е�����
SLDataType seqListAt(seqList* sl, int pos);
//�ж�˳����Ƿ�Ϊ��
int seqListEmpty(seqList* sl);
//ȷ��˳����е���Ч��Ϣ����
int seqListSize(seqList* sl);
//����˳���
void seqListDestory(seqList* sl);
//��˳������ͷ�����
void seqListPushFront(seqList* sl, SLDataType n);
//��˳������ͷɾ����
void seqListPopFront(seqList* sl);
//��˳������βɾ����
void seqListPopBack(seqList* sl);
//��ָ��λ�ò�������
void seqListInsert(seqList* sl, int pos, SLDataType n);
//ɾ��ָ��λ�õ�����
void seqListErase(seqList* sl, int pos);