#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <assert.h>
#include <string.h>

typedef int SLDataType;

#define N 100
typedef struct seqList2	//	静态顺序表,sizeof(seqList2)=404byte
{
	SLDataType _data[N];
	int _size;
}seqList2;

typedef struct seqList	//	动态顺序表,sizeof(seqList)=12byte
{
	SLDataType* _data;
	int _size;
	int _capacity;
}seqList;

//初始化顺序表
void initseqList(seqList* sl);
//对顺序表进行尾插操作
void seqListPushBack(seqList* sl, SLDataType n);
//检查顺序表容量
void seqListCheckCapacity(seqList* sl);
//打印顺序表数据
void seqListPrint(seqList* sl);
//寻找顺序表中的数据
SLDataType seqListAt(seqList* sl, int pos);
//判断顺序表是否为空
int seqListEmpty(seqList* sl);
//确认顺序表中的有效信息个数
int seqListSize(seqList* sl);