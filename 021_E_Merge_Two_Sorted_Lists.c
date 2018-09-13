#include<stdio.h>

 struct ListNode {
     int val;
     struct ListNode *next;
 };
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode head, *temp = &head;
    head.next=NULL;

    while(l1 && l2){
        if(l1->val < l2->val){
            temp->next = l1;
            l1 = l1->next;
            temp = temp->next;
        } else {
            temp->next = l2;
            l2 = l2->next;
            temp = temp->next;
        }
    }
    temp->next = l1 ? l1 : l2;
    return head.next;
}
