/*
class DLLNode {
  public:
    int data;
    DLLNode *next;
    DLLNode *prev;

    DLLNode(int val) {
        data = val;
        this->next = NULL;
        this->prev = NULL;
    }
};
*/
class Solution {
  public:
    // Function to reverse a doubly linked list
    DLLNode* reverseDLL(DLLNode* head) {
        // Your code here
        if(head==NULL || head->next==NULL) return head;
        
        DLLNode* temp = head;
        DLLNode* last= NULL;
        
        while(temp!=NULL){
            last= temp->prev;
            temp->prev= temp->next;
            temp->next= last;
            temp=temp->prev;
        }
        return last->prev;
    }
};