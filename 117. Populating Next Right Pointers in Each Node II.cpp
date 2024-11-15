class Solution {
public:
    Node* connect(Node* root) {
        if(root == NULL) return NULL;

        Node* head = root;

        while(head){
            Node* temp = new Node();
            Node* cur = temp;

            while(head){
                if(head->left){
                    cur->next = head->left;
                    cur = cur->next;
                }

                if(head->right){
                    cur->next = head->right;
                    cur = cur->next;
                }

                head = head->next;
            }

            head = temp->next;
        }

        return root;
    }
};
