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



//��������������ϲ�Ϊһ���µ�������������
//��������ͨ��ƴ�Ӹ�����������������нڵ���ɵ�




//����һ�����������һ��ʱ�临�Ӷ�ΪO(n),����ռ临�Ӷ�ΪO(1)���㷨
//�ж����Ƿ�Ϊ���Ľṹ��
//����һ�������ͷָ��A���뷵��һ��boolֵ���������Ƿ�Ϊ���Ľṹ
//��֤������С�ڵ���900��
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





//����һ����������������е�����k�����
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



//����һ������ͷ��� head �ķǿյ���������������м���
//����������м��㣬�򷵻صڶ����м���
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



//��תһ��������
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


//ɾ�������е��ڸ���ֵ val �����нڵ�
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