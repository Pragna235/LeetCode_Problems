class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        // Handling the case where the head node itself needs to be removed
        while (head != nullptr && head->val == val) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
        }

        ListNode* current = head;

        // Traverse the list and remove nodes with the target value
        while (current != nullptr && current->next != nullptr) {
            if (current->next->val == val) {
                ListNode* nodeToDelete = current->next;
                current->next = nodeToDelete->next;
                delete nodeToDelete;
            } else {
                current = current->next;
            }
        }

        return head;
    }
};
