#include <stdio.h>

int main()
{
	int* a = NULL;
	if (a)
		printf("Yes");
	else
		printf("No");
	return 0;

}



//将两个有序链表合并为一个新的有序链表并返回
//新链表是通过拼接给定的两个链表的所有节点组成的




//对于一个链表，请设计一个时间复杂度为O(n),额外空间复杂度为O(1)的算法
//判断其是否为回文结构。
//给定一个链表的头指针A，请返回一个bool值，代表其是否为回文结构
//保证链表长度小于等于900。
//class PalindromeList
//{
//public:
//    bool chkPalindrome(ListNode* A)
//    {
//        if (A == NULL || A->next == NULL)
//            return true;
//        ListNode* newHead, * fast, * slow, * next;
//        newHead = NULL;
//        fast = slow = A;
//        while (fast && fast->next)
//        {
//            fast = fast->next;
//            slow = slow->next;
//        }
//        while (slow->next)
//        {
//            next = slow->next;
//            slow->next = newHead;
//            newHead = slow;
//            slow = next;
//        }
//        while (slow && A)
//        {
//            if (slow->val != A->val)
//                return false;
//            A = A->next;
//            slow = slow->next;
//        }
//        return true;
//    }
//};





//输入一个链表，输出该链表中倒数第k个结点
//ListNode* FindKthToTail(ListNode* pListHead, unsigned int k)
//{
//    ListNode* fast, * slow;
//    slow = pListHead;
//    while (k--)
//    {
//        if (fast)
//            fast = fast->next;
//        else
//            return NULL;
//    }
//    while (fast)
//    {
//        fast = fast->next;
//        slow = slow->next;
//    }
//    return slow;
//}



//给定一个带有头结点 head 的非空单链表，返回链表的中间结点
//如果有两个中间结点，则返回第二个中间结点
//struct ListNode* middleNode(struct ListNode* head)
//{
//    struct ListNode* slow, * fast;
//    slow = head;
//    fast = head;
//    while (fast && fast->next)
//    {
//        fast = fast->next->next;
//        slow = slow->next;
//    }
//    return slow;
//}



//反转一个单链表
//struct ListNode* reverseList(struct ListNode* head)
//{
//    if (head == NULL)
//        return head;
//    struct ListNode* next, * cur, * newHead;
//    cur = head;
//    newHead = NULL;
//    next = NULL;
//    while (cur)
//    {
//        next = cur->next;
//        cur->next = newHead;
//        newHead = cur;
//        cur = next;
//    }
//    return newHead;
//}
//
//struct ListNode* reverseList(struct ListNode* head)
//{
//    if (head == NULL)
//        return head;
//    struct ListNode* n1, * n2, * n3;
//    n1 = NULL;
//    n2 = head;
//    n3 = n2->next;
//    while (n2)
//    {
//        n2->next = n1;
//        n1 = n2;
//        n2 = n3;
//        if (n3)
//            n3 = n3->next;
//    }
//    return n1;
//}


//删除链表中等于给定值 val 的所有节点
//struct ListNode* removeElements(struct ListNode* head, int val)
//{
//    struct ListNode* prev, * cur;
//    prev = NULL;
//    cur = head;
//    while (cur)
//    {
//        if (cur->val == val)
//        {
//            struct ListNode* next = cur->next;
//            free(cur);
//            if (prev == NULL)
//                head = next;
//            else
//                prev->next = next;
//            cur = next;
//        }
//        else
//        {
//            prev = cur;
//            cur = cur->next;
//        }
//    }
//    return head;
//}