#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include <ctype.h>
#include <math.h>
#include <windows.h>


//ʹ�����ԣ�C����
//���ڷǸ����� X ���ԣ�X ��������ʽ��ÿλ���ְ������ҵ�˳���γɵ����顣
//���磬��� X = 1231����ô��������ʽΪ [1,2,3,1]��
//�����Ǹ����� X ��������ʽ A���������� X + K ��������ʽ��

int* addToArrayForm(int* A, int ASize, int K, int* returnSize)
{
	//����K��λ��
	int len = 0;
	int tmp = K;
	while (tmp)
	{
		len++;
		tmp /= 10;
	}
	//���ٿռ䣬ע�����λ���ܴ��ڽ�λ�����
	int arrLen = ASize > len ? ASize + 1 : len + 1;
	int* arr = (int*)malloc(sizeof(int) * arrLen);

	//��λ���
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
	//�ж����λ�Ƿ���ڽ�λ
	if (step == 1)
	{
		arr[index++] = step;
	}
	//Ϊ�˷�����������β�壬��������������洢����Ҫ������������������
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



//ԭ���Ƴ����������е�Ԫ��val��Ҫ��ʱ�临�Ӷ�ΪO(N)���ռ临�Ӷ�ΪO(1)
//����˼·����������Ҫɾ����Ԫ���ú����Ԫ�ظ��ǵ�
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
//����k��
//void reverse(int* nums, int start, int end)
//{
//    while (start < end)
//    {
//        nums[start] = nums[start] ^ nums[end];  //  ������[���]ʼ��Ϊ��
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

////ɾ�����������е��ظ���
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