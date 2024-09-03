class node{
    public:
    int val;
    node *next;
    node(int data)
    {
        val=data;
        next=NULL;
    }
};
class MyLinkedList {
public:
    node*head;
    MyLinkedList() {
        head=NULL;
    }
    int length(){
        int count=0;
        node*temp=head;
        while(temp!=NULL){
            count++;
            temp=temp->next;
        }
    return count;
    }
    int get(int k) {
        int len=length();
        if (head == NULL) return -1;
        else if(len<k) return -1;
        else{
            int count=0;
            node*temp=head;
            while(count<k){
                temp=temp->next;
                count++;
            }
            if (temp == NULL) return -1;
            return temp->val; 
        }
    }
    
    void addAtHead(int value) {
        node *new_node=new node(value);
        new_node->next=head;
        head=new_node;
    }
    
    void addAtTail(int value) {
       node *new_node=new node(value);
        if(head==NULL){
            head=new_node;
        }
        else{
            node*temp=head;
            while(temp->next!=NULL){
                temp=temp->next;
            }
            temp->next=new_node;
        } 
    }
    
    void addAtIndex(int k, int value) {
        node*new_node=new node(value);
        if(k==0){
            addAtHead(value);
        }
        else{
            int count=0;
            node*temp=head;
            while(temp!=NULL && count<k-1){
                temp=temp->next;
                count++;
            }
            if (temp == NULL) return;
            node*right=temp->next;
            temp->next=new_node;
            new_node->next=right;
        }
    }
    
    void deleteAtIndex(int k) {
        if (head == NULL) return;
        else if(k==0){
            node*del=head;
            head=head->next;
            delete del;
        }
        else{
            int count=0;
            node*temp=head;
            while(count<k-1){
                temp=temp->next;
                count++;
            }
            if (temp == NULL || temp->next == NULL) return;
            node*del=temp->next;
            temp->next=temp->next->next;
            delete del;
        }
    }
};
