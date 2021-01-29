#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int HPDataType;
typedef struct Heap
{
	HPDataType* _a;
	int _size;
	int _capacity;
}Heap;

// 交换
void Swap(HPDataType* a, HPDataType* b)
{
	HPDataType tmp = *a;
	*a = *b;
	*b = tmp;
}

// 堆的打印
void HeapPrint(Heap* hp)
{
	int i;
	for (i = 0; i < hp->_size; i++)
	{
		printf("%d ", hp->_a[i]);
	}
	printf("\n");
}

// 堆容量的判断
void HeapCapacity(Heap* hp)
{
	if (hp == NULL)
		return;
	if (hp->_capacity <= hp->_size)
	{
		int newcapacity = hp->_capacity == 0 ? 1 : 2 * hp->_capacity;
		hp->_a = (int*)realloc(hp->_a, sizeof(int) * newcapacity);
		hp->_capacity = newcapacity;
	}
}

// 堆的向下调整（小堆）
void HeapShiftDown(HPDataType* a, int n, int curPos)
{
	int child = 2 * curPos + 1;
	while (child < n)
	{
		if ((a[child] > a[child + 1]) && ((child + 1) < n))
			child++;
		if (a[child] < a[curPos])
		{
			Swap(&(a[child]), &(a[curPos]));
			curPos = child;
			child = 2 * curPos + 1;
		}
		else
			break;
	}
}

// 堆的向上调整（小堆）
void HeapShiftUp(HPDataType * a, int n, int curPos)
{
	if (a == NULL)
		return;
	int parent = (curPos - 1) / 2;
	while (curPos > 0)
	{
		if (a[curPos] < a[parent])
		{
			Swap(&a[curPos], &a[parent]);
			curPos = parent;
			parent = (curPos - 1) / 2;
		}
		else
			break;
	}
}

// 堆的构建（小堆）
void HeapCreate(Heap* hp, HPDataType* a, int n)
{
	if (hp == NULL || a == NULL)
		return;
	hp->_a = (HPDataType*)malloc(sizeof(HPDataType) * n);
	hp->_size = n;
	hp->_capacity = n;
	int i;
	for (i = 0; i < n; i++)
	{
		hp->_a[i] = a[i];
	}
	for (i = (n - 2) / 2; i >= 0; i--)
	{
		HeapShiftDown(hp->_a, hp->_size, i);
	}
}

// 堆的销毁
void HeapDestory(Heap* hp)
{
	if (hp == NULL)
		return;
	free(hp->_a);
	hp->_a = NULL;
	hp->_size = hp->_capacity = 0;
}

// 堆的插入
void HeapPush(Heap* hp, HPDataType x)
{
	if (hp == NULL)
		return;
	HeapCapacity(hp);
	hp->_a[hp->_size++] = x;
	HeapShiftUp(hp->_a, hp->_size, hp->_size - 1);
}

// 堆的删除
void HeapPop(Heap* hp)
{
	if (hp == NULL || hp->_size == 0)
		return;
	Swap(&hp->_a[0], &hp->_a[hp->_size - 1]);
	hp->_size--;
	HeapShiftDown(hp->_a, hp->_size, 0);
}

// 取堆顶的数据
HPDataType HeapTop(Heap* hp)
{
	assert(hp);
	return hp->_a[0];
}

// 堆的数据个数
int HeapSize(Heap* hp)
{
	assert(hp);
	return hp->_size;
}

// 堆的判空
int HeapEmpty(Heap* hp)
{
	assert(hp);
	return hp->_size == 0;
}

// 对数组进行堆排序
void HeapSort(int* a, int n)
{
	int i, end;
	for (i = (n - 2) / 2; i >= 0; i--)
	{
		HeapShiftDown(a, n, i);	//	建小堆
	}
	end = n - 1;
	while (end > 0)
	{
		Swap(&a[0], &a[end]);
		HeapShiftDown(a, end, 0);
		end--;
	}
}

int main()
{
	int a[4] = { 2,1,4,3 };
	HeapSort(a, 4);
	int i = 0;
	for (i; i < 4; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
	return 0;
}

//void PrintTopk(int* a, int n, int k)
//{
//	Heap hp;
//	HeapCreate(&hp, a, n);
//	int end = n - 1;
//	while (end > 0)
//	{
//		Swap(&(hp._a[0]), &(hp._a[end]));
//		HeapShiftDown(hp._a, end, 0);
//		end--;
//	}
//	int i = 0;
//	for (i; i < k; i++)
//	{
//		printf("%d ", hp._a[i]);
//	}
//}
//void TestTopk()
//{
//	int n = 10000;
//	int* a = (int*)malloc(sizeof(int) * n);
//	srand(time(0));
//	for (int i = 0; i < n; ++i)
//	{
//		a[i] = rand() % 1000000;
//	}
//	a[5] = 1000000 + 1;
//	a[1231] = 1000000 + 2;
//	a[531] = 1000000 + 3;
//	a[5121] = 1000000 + 4;
//	a[115] = 1000000 + 5;
//	a[2335] = 1000000 + 6;
//	a[9999] = 1000000 + 7;
//	a[76] = 1000000 + 8;
//	a[423] = 1000000 + 9;
//	a[3144] = 1000000 + 10;
//	PrintTopk(a, n, 10);
//}
//
//int main()
//{
//	TestTopk();
//	return 0;
//}