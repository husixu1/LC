#include<iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        int count = 0;
        for(ListNode *p = head; p; p = p->next, count++);
        if(count == 0)
            k = 0;
        else
            k%=count;

        ListNode newHead(0);
        ListNode *frontRec, *front = head, *tail = head, *newp = &newHead;
        for(int i=0; i<k; i++)
            tail = tail->next;
        for(; tail; front = front->next, tail = tail->next);
        frontRec = front;
        for(; front; newp->next = new ListNode(front->val), newp = newp->next, front = front->next);
        newp->next = head;
        for(; newp->next != frontRec; newp = newp->next);
        newp->next = NULL;
        return newHead.next;
    }
};
