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
class Solution {
public:
    int lengthList(ListNode* head){
        int cnt = 0;
        ListNode* temp = head;
        while(temp){
            cnt++;
            temp=temp->next;
        }
        return cnt;
    }
    ListNode* middleNode(ListNode* head) {
        if(head==NULL) return head;
        int n = lengthList(head);
        int mid = (n/2)+1;
        int cnt=0;
        ListNode* temp = head;
        while(temp){
            cnt++;
            if(cnt==mid){
                head = temp;
                break;
            }
            temp=temp->next;
        }
        return head;

    }
};
