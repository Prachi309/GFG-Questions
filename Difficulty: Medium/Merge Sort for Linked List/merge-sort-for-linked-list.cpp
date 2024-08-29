//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void printList(Node *node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << "\n";
}


// } Driver Code Ends
/*
The structure of linked list is the following

struct Node {
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    // Function to sort the given linked list using Merge Sort.
    
     Node*  findMiddle(Node*  head){
        
        Node*  slow= head;
        Node*  fast= head->next;
        
        while(fast!=NULL && fast->next!=NULL){
            slow= slow->next;
            fast= fast->next->next;
        }
        return slow;
        
    }
    
    Node* merge(Node* list1,Node* list2){
        
        Node*  dummy = new Node(-1);
        Node*  temp= dummy;
        while(list1!=NULL && list2!=NULL){
            if(list1->data < list2->data){
                temp->next= list1;
                temp=list1;
                list1=list1->next;
            }
            else{
                temp->next= list2;
                temp=list2;
                list2=list2->next;
            }
            
        }
        if(list1) temp->next =list1;
        if(list2) temp->next = list2;
        
        
        return dummy->next;
    }
    
    Node* mergeSort(Node* head) {
        // your code here
         if(head==NULL || head->next==NULL) return head;
        
        Node* mid= findMiddle(head);
        Node* right = mid->next;
        mid->next= NULL;
        Node* left= head;
        
        left = mergeSort(left);
        right= mergeSort(right);
        
        return merge(left,right);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;

        // Read numbers from the input line
        while (ss >> number) {
            arr.push_back(number);
        }
        Node *head = nullptr;
        // Check if the array is empty
        if (!arr.empty()) {
            head = new Node(arr[0]);
            Node *tail = head;
            for (size_t i = 1; i < arr.size(); ++i) {
                tail->next = new Node(arr[i]);
                tail = tail->next;
            }
        }
        Solution obj;
        Node *ans = obj.mergeSort(head);
        printList(ans);
    }
    return 0;
}
// } Driver Code Ends