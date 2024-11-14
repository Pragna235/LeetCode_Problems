/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
ListNode* getKthNode(ListNode* temp, int k){
    k-=1;
    while(temp && k>0){
        k--;
        temp=temp->next;
    }
    return temp;
}
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* tail = head;
        if(!head || !head->next) return head;
        int len = 1;
        while(tail->next!=NULL){
            tail=tail->next;
            len++;
        }
        if(k%len==0) return head;
        k = k%len;

        tail->next = head;
        ListNode* kthNode = getKthNode(temp, len-k);
        head = kthNode->next;
        kthNode->next = NULL;

        return head;
    }
};
