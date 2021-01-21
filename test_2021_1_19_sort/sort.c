#include <stdio.h>
#include <stdlib.h>
#include "list.h"

// 交换函数
void Swap(int* arr, int i, int j)
{
	int tmp = arr[i];
	arr[i] = arr[j];
	arr[j] = tmp;
}

// 非递归快速排序——保存每个子区间——优点：不会导致栈溢出
int ReferencePositionNonRecursion(int* arr, int n)
{
	seqList sq;
	initseqList(&sq);
	seqListPushBack(&sq, n - 1);
	seqListPushBack(&sq, 0);
	while (!seqListEmpty(&sq))
	{
		int left = seqListBack(&sq);
		seqListPopBack(&sq);
		int right = seqListBack(&sq);
		seqListPopBack(&sq);

		int div = ReferencePosition(arr, left, right);

		if (left < div - 1)
		{
			seqListPushBack(&sq, div - 1);
			seqListPushBack(&sq, left);
		}
		if (div + 1 < right)
		{
			seqListPushBack(&sq, right);
			seqListPushBack(&sq, div + 1);
		}
	}
}


// Pointer排序——快速排序
int ReferencePositionPointer(int* arr, int begin, int end)
{
	int prev = begin;
	int cur = begin + 1;
	int refvalue = arr[begin];
	while (cur <= end)
	{
		if (arr[cur] < refvalue && ++prev != cur)
		{
			Swap(arr, prev, cur);
		}
		cur++;
	}
	Swap(arr, begin, prev);
	return prev;
}

// 三数取中法——快速排序
int midposition(int* arr, int begin, int end)
{
	int mid = begin + (end - begin) / 2;
	if (arr[begin] > arr[mid])
	{
		if (arr[mid] > arr[end])
		{
			return mid;
		}
		else if (arr[begin] > arr[end])
		{
			return end;
		}
		else
			return begin;

	}
	else
	{
		if (arr[end] > arr[mid])
			return mid;
		else if (arr[begin] > arr[mid])
			return begin;
		else
			return end;
	}
}

// Hoare排序——快速排序
int ReferencePositionHoare(int* arr, int begin, int end)
{
	int mid = midposition(arr, begin, end);
	Swap(arr, mid, begin);
	int refvalue = arr[begin];
	int refposition = begin;
	while (begin < end)
	{
		while (begin < end && arr[end] >= refvalue)
		{
			end--;
		}
		arr[begin] = arr[end];
		while (begin < end && arr[begin] <= refvalue)
		{
			begin++;
		}
		arr[end] = arr[begin];
	}
	arr[begin] = refvalue;
	return begin;
}

// 获取基准位置——快速排序
int ReferencePosition(int* arr, int begin, int end)
{
	int mid = midposition(arr, begin, end);
	Swap(arr, mid, begin);
	int refvalue = arr[begin];
	int refposition = begin;
	while (begin < end)
	{
		while (begin < end && arr[end] >= refvalue)
		{
			end--;
		}
		while (begin < end && arr[begin] <= refvalue)
		{
			begin++;
		}
		Swap(arr, begin, end);
	}
	Swap(arr, refposition, begin);
	return begin;
}

// 快速排序法 O(n^2)
// 数据有序时，可能会出现栈溢出
// 优化方法：三数取中法
// 优化后 O(nlogn) 相当于栈的调用层数
void QuickSort(int* arr, int begin, int end)
{
	if (begin >= end)
		return;
	int refposition = ReferencePositionPointer(arr, begin, end);
	QuickSort(arr, begin, refposition - 1);
	QuickSort(arr, refposition + 1, end);
}

// 冒泡排序
// O(n^2)，有序：O(n)
// 稳定
void BubbleSort(int* arr, int n)
{
	int i = 0;
	int j;
	for (i = 0; i < n - 1; i++)
	{
		int flag = 0;
		for (j = 0; j < n - 1 - i; j++)
		{
			if (arr[j + 1] < arr[j])
			{
				Swap(arr, i, j);
				flag = 1;
			}
		}
		if (flag == 0)
			break;
	}
}


// 堆的向下调整（小堆）
void HeapShiftDown(int* arr, int n, int curPos)
{
	int child = 2 * curPos + 1;
	while (child < n)
	{
		if ((arr[child] > arr[child + 1]) && ((child + 1) < n))
			child++;
		if (arr[child] < arr[curPos])
		{
			Swap(arr, child, curPos);
			curPos = child;
			child = 2 * curPos + 1;
		}
		else
			break;
	}
}

// 堆排序
void HeapSort(int* arr, int n)
{
	int i, end;
	for (i = (n - 2) / 2; i >= 0; i--)
	{
		HeapShiftDown(arr, n, i);	//	建小堆
	}
	end = n - 1;
	while (end > 0)
	{
		Swap(arr, end, 0);
		HeapShiftDown(arr, end, 0);
		end--;
	}
}

// 老师写的改进选择排序
void ImprovedSelectSort(int* arr, int n)
{
	int start = 0;
	int end = n - 1;
	int i;
	while (start < end)
	{
		int minIdx = start;
		int maxIdx = start;
		for (i = start + 1; i <= end; i++)
		{
			if (arr[i] < arr[minIdx])
				minIdx = i;
			if (arr[i] > arr[maxIdx])
				maxIdx = i;
		}
		Swap(arr, start, minIdx);
		if (maxIdx == start)
			maxIdx = minIdx;
		Swap(arr, end, maxIdx);
		start++;
		end--;
	}
	
}



// 老师写的选择排序
// O(n^2)
void SelectSort(int* arr, int n)
{
	int start = 0;
	int end = n - 1;
	while (start < end )
	{
		int minIdx = start;
		int i;
		for (i = start + 1; i <= end; i++)
		{
			if (arr[i] < arr[minIdx])	//	if(arr[i] <= arr[minIdx]) 不稳定
				minIdx = i;
		}
		Swap(arr, start, minIdx);
		start++;
	}
}

// 老师写的希尔排序
// O(n^2)
// 不稳定
void ShellSort(int* arr, int n)
{
	int gap = n;
	int i = 0;
	while (gap >= 1)
	{
		gap /= 2;
		for (i = gap; i < n; i++)
		{
			int end = i - gap;
			int data = arr[i];
			while (end >= 0 && arr[end] > data)
			{
				arr[end + gap] = arr[end];
				end = end - gap;
			}
			arr[end + gap] = data;
		}
	}
}

// 老师写的插入排序
// 时间复杂度：O(n^2)
void InsertSort(int* arr, int n)
{
	int i;
	for (i = 1; i < n; i++ )
	{
		int end = i - 1;
		int data = arr[i];
		while (end >= 0 && arr[end] > arr[i])
		{
			arr[end + 1] = arr[end];
			end--;
		}
		arr[end + 1] = data;
	}
}

int main()
{
	int arr[] = { 5,1,4,3,2 };
	ReferencePositionNonRecursion(arr, 5);
	printf("\n");
	return 0;
}