#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include <ctype.h>
#include <math.h>
#include <windows.h>


//使用语言：C语言
//对于非负整数 X 而言，X 的数组形式是每位数字按从左到右的顺序形成的数组。
//例如，如果 X = 1231，那么其数组形式为 [1,2,3,1]。
//给定非负整数 X 的数组形式 A，返回整数 X + K 的数组形式。

int* addToArrayForm(int* A, int ASize, int K, int* returnSize)
{
	//计算K的位数
	int len = 0;
	int tmp = K;
	while (tmp)
	{
		len++;
		tmp /= 10;
	}
	//开辟空间，注意最高位可能存在进位的情况
	int arrLen = ASize > len ? ASize + 1 : len + 1;
	int* arr = (int*)malloc(sizeof(int) * arrLen);

	//逐位相加
	int index = 0;
	int end = ASize - 1;
	int step = 0;
	while (end >= 0 || K > 0)
	{
		int cursum = step;
		if (end >= 0)
		{
			cursum += A[end];
		}
		if (K > 0)
		{
			cursum += (K % 10);
		}
		if (cursum > 9)
		{
			step = 1;
			cursum -= 10;
		}
		else
		{
			step = 0;
		}
		arr[index++] = cursum;
		end--;
		K /= 10;
	}
	//判断最高位是否存在进位
	if (step == 1)
	{
		arr[index++] = step;
	}
	//为了方便对数组进行尾插，所以数据是逆序存储，故要对数组进行逆序操作。
	int start = 0;
	end = index - 1;
	while (start < end)
	{
		int tmp = arr[start];
		arr[start] = arr[end];
		arr[end] = tmp;
		start++;
		end--;
	}
	*returnSize = index;
	return arr;
}



//原地移除数组中所有的元素val，要求时间复杂度为O(N)，空间复杂度为O(1)
//解题思路：将数组中要删除的元素用后面的元素覆盖掉
//int removeElement(int* nums, int numsSize, int val)
//{
//    int left = 0;
//    int right = 0;
//    while (right < numsSize)
//    {
//        if (nums[right] != val)
//        {
//            nums[left++] = nums[right++];
//        }
//        else
//        {
//            right++;
//        }
//    }
//    return left;
//}
//
//
//右旋k次
//void reverse(int* nums, int start, int end)
//{
//    while (start < end)
//    {
//        nums[start] = nums[start] ^ nums[end];  //  与自身[异或]始终为零
//        nums[end] = nums[start] ^ nums[end];
//        nums[start] = nums[start] ^ nums[end];
//        start++;
//        end--;
//    }
//}
//
//void rotate(int* nums, int numsSize, int k)
//{
//    k %= numsSize;
//    reverse(nums, 0, numsSize - k - 1);
//    reverse(nums, numsSize - k, numsSize - 1);
//    reverse(nums, 0, numsSize - 1);
//}
//
//int main()
//{
//    int i = 0;
//    int arr[] = { 1,2,3,4,5,6 };
//    for (i = 0; i < 6; i++)
//    {
//        printf("%d ", arr[i]);
//    }
//    rotate(arr, 1, 1);
//    printf("\n");
//    for (i = 0; i < 6; i++)
//    {
//        printf("%d ", arr[i]);
//    }
//    return 0;
//}

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