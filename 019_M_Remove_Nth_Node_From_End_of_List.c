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

typedef struct ListNode Node;

struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    Node *front = head, *end = head;
    for(int i=0; i<n; i++)
        end = end->next;
    if(!end){
        head = front->next;
        return head;
    }

    while(end->next){
        end = end->next;
        front = front->next;
    }
    front->next = front->next->next;

    return head;
}
