typedef struct ListNode {
    int val;
    struct ListNode *next;
}Node;

#include<stdlib.h>

// problem answer starts here
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

typedef struct ListNode Node;

typedef struct _headNode{
    Node *node;
    int index;
    struct _headNode *next;
}headNode;


void insert(headNode *head, Node *node){
    headNode *temp = head->next, *tempShadow = head;
    for(;temp && temp->node->val < node->val; tempShadow = temp, temp = temp->next);
    headNode *new = (headNode *)malloc(sizeof(headNode));

    new->next = temp;
    tempShadow->next = new;

    new->node = node;
}

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
    Node resultHead;
    resultHead.next = NULL;
    Node *resultp = &resultHead;
    headNode head;

    head.next = NULL;

    //initilization
    for(int i=0; i<listsSize; ++i)
        if(lists[i]) insert(&head, lists[i]);

    for(headNode *temp = head.next; temp; temp = head.next){
        resultp->next = temp->node;
        resultp = resultp->next;

        head.next = temp->next;

        if(temp->node->next)
            insert(&head, temp->node->next);

        free(temp);
    }
    return resultHead.next;
}


