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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        // Edge case: if left is equal to right, no reversal is needed
        if(left == right) return head;
        
        // Step 1: Extract values to vector
        vector<int> vec;
        ListNode *p = head;
        while(p) {
            vec.push_back(p->val);
            p = p->next;
        }
        
        // Step 2: Reverse the sublist in vector
        reverse(vec.begin() + left - 1, vec.begin() + right);
        
        // Step 3: Reconstruct the linked list from the vector
        ListNode *head2 = nullptr, *tail = nullptr;
        for(int i : vec) {
            ListNode *node = new ListNode(i);
            if(!head2) {
                head2 = node;
                tail = head2;
            } else {
                tail->next = node;
                tail = tail->next;
            }
        }
        
        // Return the new head
        return head2;
    }
};
