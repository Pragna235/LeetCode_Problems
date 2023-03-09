/*
* Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_set<ListNode*>s;
        ListNode* curr=head;
        while(curr!=NULL){
            if(s.find(curr)!=s.end()){
                return curr;
            }else{
                s.insert(curr);
                curr=curr->next;
            }
        }
        return NULL;
    }
};
