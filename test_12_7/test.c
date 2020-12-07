#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include <ctype.h>
#include <math.h>
#include <windows.h>

//右旋k次
void reverse(int* nums, int start, int end)
{
    while (start <= end)
    {
        nums[start] = nums[start] ^ nums[end];  //  与自身[异或]始终为零
        nums[end] = nums[start] ^ nums[end];
        nums[start] = nums[start] ^ nums[end];
        start++;
        end--;
    }
}

void rotate(int* nums, int numsSize, int k)
{
    k %= numsSize;
    reverse(nums, 0, numsSize - k - 1);
    reverse(nums, numsSize - k, numsSize - 1);
    reverse(nums, 0, numsSize - 1);
}

int main()
{
    int i = 0;
    int arr[] = { 1,2,3,4,5,6 };
    for (i = 0; i < 6; i++)
    {
        printf("%d ", arr[i]);
    }
    rotate(arr, 6, 2);
    printf("\n");
    for (i = 0; i < 6; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}

////删除排序数组中的重复项
//int main()
//{
//	int arr[] = { 0,1,1,2,2,3,3,3,4 };	//	arr[]={ 0,1,2,3,4 }
//	int size = sizeof(arr) / sizeof(arr[0]);
//	int start = 0;
//	int end = start;
//	int index = 1;
//	while (end < size)
//	{
//		if (arr[start] != arr[end])
//		{
//			start = end;
//			arr[index++] = arr[start];
//		}
//		end++;
//	}
//	int i = 0;
//	for (i = 0; i < size ; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}