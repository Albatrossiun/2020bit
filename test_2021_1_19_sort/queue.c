#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <math.h>

typedef int QDataType;
typedef struct QListNode
{
	struct QListNode* _next;
	QDataType _data;
}QNode;

typedef struct Queue
{
	QNode* _front;
	QNode* _rear;
}Queue;

// ��ʼ������ 
void QueueInit(Queue* q)
{
	if (q == NULL)
		return;
	q->_front = NULL;
	q->_rear = NULL;
}

// ��β����� 
void QueuePush(Queue* q, QDataType data)
{
	if (q == NULL)
		return;
	QNode* newNode = (QNode*)malloc(sizeof(QNode));
	newNode->_next = NULL;
	newNode->_data = data;
	if (q->_front == NULL)
	{
		q->_front = newNode;
		q->_rear = newNode;
	}
	else
	{
		q->_rear->_next = newNode;
		q->_rear = newNode;
	}
}

// ��ͷ������ 
void QueuePop(Queue* q)
{
	if (q == NULL || q->_front == NULL)
		return;
	QNode* next = q->_front->_next;
	free(q->_front);
	q->_front = next;

	if (q->_front == NULL)
		q->_rear = NULL;
}

// ��ȡ����ͷ��Ԫ�� 
QDataType QueueFront(Queue* q)
{
	assert(q);
	assert(q->_front);
	return q->_front->_data;
}

// ��ȡ���ж�βԪ�� 
QDataType QueueBack(Queue* q)
{
	assert(q);
	assert(q->_rear);
	return q->_rear->_data;
}

// ��ȡ��������ЧԪ�ظ��� 
int QueueSize(Queue* q)
{
	assert(q);
	QNode* cur = q->_front;
	int count = 0;
	while (cur)
	{
		count++;
		cur = cur->_next;
	}
	return count;
}

// �������Ƿ�Ϊ�գ����Ϊ�շ��ط�����������ǿշ���0 
int QueueEmpty(Queue* q)
{
	assert(q);
	if (q->_front == NULL)
		return 1;
	else
		return 0;
}

// ���ٶ��� 
void QueueDestroy(Queue* q)
{
	if (q == NULL || q->_front == NULL)
		return;
	while (q->_front)
	{
		QueuePop(q);
	}
}
