#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

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

// 初始化队列 
void QueueInit(Queue** q)
{
	if (q == NULL)
		return;
	(*q) = (Queue*)malloc(sizeof(Queue));
	(*q)->_front = NULL;
	(*q)->_rear = NULL;
}

// 队尾入队列 
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

// 队头出队列 
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

// 获取队列头部元素 
QDataType QueueFront(Queue* q)
{
	assert(q);
	assert(q->_front);
	return q->_front->_data;
}

// 获取队列队尾元素 
QDataType QueueBack(Queue* q)
{
	assert(q);
	assert(q->_rear);
	return q->_rear->_data;
}

// 获取队列中有效元素个数 
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

// 检测队列是否为空，如果为空返回非零结果，如果非空返回0 
int QueueEmpty(Queue* q)
{
	assert(q);
	if (q->_front == NULL)
		return 1;
	else
		return 0;
}

// 销毁队列 
void QueueDestroy(Queue* q)
{
	if (q == NULL || q->_front == NULL)
		return;
	while (q->_front)
	{
		QueuePop(q);
	}
}

void test()
{
	Queue* q;
	QueueInit(&q);
	QueuePush(q, 2);
	QueuePush(q, 4);
	QueuePush(q, 6);
	QueuePush(q, 8);
	QueuePop(q);
	int count = QueueSize(q);
	QNode* cur = q->_front;
	while(count)
	{
		count--;
		printf("%d\n", cur->_data);
		cur = cur->_next;
	}
}

int main()
{
	test();
	return 0;
}



//循环队列
typedef struct
{
	int _front;
	int _rear;
	int _k;
	int* _data;
}MyCircularQueue;


MyCircularQueue* myCircularQueueCreate(int k)
{
	MyCircularQueue* cq = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
	cq->_data = (int*)malloc(sizeof(int) * (k + 1));
	cq->_front = 0;
	cq->_rear = 0;
	cq->_k = k;
	return cq;
}


bool myCircularQueueIsEmpty(MyCircularQueue* obj)
{
	return obj->_front == obj->_rear;
}


bool myCircularQueueIsFull(MyCircularQueue* obj)
{
	return ((obj->_rear + 1) % (obj->_k + 1)) == obj->_front;
}


bool myCircularQueueEnQueue(MyCircularQueue* obj, int value)
{
	if (myCircularQueueIsFull(obj))
		return false;
	obj->_data[obj->_rear++] = value;
	if (obj->_rear > obj->_k)
		obj->_rear = 0;
	return true;
}


bool myCircularQueueDeQueue(MyCircularQueue* obj)
{
	if (myCircularQueueIsEmpty(obj))
		return false;
	obj->_front++;
	if (obj->_front > obj->_k)
		obj->_front = 0;
	return true;
}


int myCircularQueueFront(MyCircularQueue* obj)
{
	if (myCircularQueueIsEmpty(obj))
		return -1;
	return obj->_data[obj->_front];
}


int myCircularQueueRear(MyCircularQueue* obj)
{
	if (myCircularQueueIsEmpty(obj))
		return -1;
	if (obj->_rear == 0)
		return obj->_data[obj->_k];
	else
		return obj->_data[obj->_rear - 1];
}


void myCircularQueueFree(MyCircularQueue* obj)
{
	free(obj->_data);
	free(obj);
}