//{ Driver Code Starts
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

Node* buildList() {
    vector<int> arr;
    string input;
    getline(cin, input);
    stringstream ss(input);
    int number;
    while (ss >> number) {
        arr.push_back(number);
    }
    if (arr.empty()) {
        return NULL;
    }
    int val = arr[0];
    int size = arr.size();

    Node* head = new Node(val);
    Node* tail = head;

    for (int i = 1; i < size; i++) {
        val = arr[i];
        tail->next = new Node(val);
        tail = tail->next;
    }

    return head;
}

void printList(Node* n) {
    while (n) {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution {
    Node* reverseLL(Node* head){
        if(head==NULL || head->next==NULL) return head;
        
        Node* newH=reverseLL(head->next);
            Node* front = head->next;
            front->next= head;
            head->next=NULL;
            return newH;
    }
    
    
  public:
    // Function to add two numbers represented by linked list.
    Node* addTwoLists(Node* l1, Node* l2) {
        // code here
         Node* t1= reverseLL(l1);
        Node* t2= reverseLL(l2);
        Node* dummy= new Node(-1);
        int carry=0;
        Node* curr= dummy;
        
        while(t1 !=NULL || t2!=NULL || carry!=0){
             int sum = carry;
            if(t1) {
                sum+=t1->data; 
                t1 =t1->next;
            }
            if(t2) {
                sum+= t2->data; 
                t2= t2->next;
            }
            Node* newnode = new Node(sum%10);
            curr->next= newnode;
            curr=curr->next;
            carry= sum/10;
      
         
            
        }
        if(carry){
             Node* newnode = new  Node(carry);
            curr->next= newnode;
        }
        
       curr= reverseLL(dummy->next);
        //remove extra zeros from front
	      while(curr->data==0){
           curr = curr->next;
	      }
	      
        return curr;
       
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To ignore the newline character after the integer input

    while (t--) {
        Node* num1 = buildList();
        Node* num2 = buildList();
        Solution ob;
        Node* res = ob.addTwoLists(num1, num2);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends