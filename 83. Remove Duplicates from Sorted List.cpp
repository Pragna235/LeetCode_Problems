class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return head; // Early return if the list is empty

        ListNode* temp = head;
        
        while (temp && temp->next) { // Check for temp->next to ensure it's safe
            if (temp->val == temp->next->val) {
                ListNode* duplicate = temp->next;
                temp->next = temp->next->next;
                delete duplicate; // Delete the duplicate node
            } else {
                temp = temp->next; // Move to the next node if no duplicate
            }
        }
        return head;
    }
};
