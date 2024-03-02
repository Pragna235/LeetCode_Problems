/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 struct
    ListNode * oddEvenList(struct
    ListNode * head){

    if (head == NULL || head->next == NULL)
    return head;
    struct
    ListNode * oddHead = head;
    struct
    ListNode * evenHead = head->next;
    struct
    ListNode * odd = head;
    struct
    ListNode * even = head->next;

    while (odd->next != NULL && even->next != NULL){
    odd->next = odd->next->next;
    even->next = even->next->next;
    odd = odd->next;
    even = even->next;
    }
    odd->next = evenHead;
    return oddHead;
    }
