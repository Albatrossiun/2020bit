#include <stdio.h>

//��������������ϲ�Ϊһ���µ�������������
//��������ͨ��ƴ�Ӹ�����������������нڵ���ɵ�



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