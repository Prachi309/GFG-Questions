//{ Driver Code Starts
//

#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void printPostOrder(Node *root)
{
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}

// } Driver Code Ends

/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
class Solution{
    public:
    
    Node* build(int preorder[],int preStart, int preEnd, int inorder[], int inStart, int inEnd,  unordered_map<int,int>&mpp){
        if(preStart>preEnd || inStart> inEnd) return NULL;
        
        Node* root = new Node (preorder[preStart]);
        int inroot= mpp[root->data];
        int numsleft = inroot-inStart;
        
        root->left= build(preorder, preStart+1, preStart+numsleft, inorder,inStart, inroot-1, mpp);
        root->right= build(preorder, preStart+1+numsleft, preEnd, inorder,inroot+1, inEnd, mpp);
        
        return root;
    }
    
    Node* buildTree(int in[],int pre[], int n)
    {
        // Code here
         unordered_map<int,int>mpp;
        for(int i=0;i<n;i++){
            mpp[in[i]]=i;
        }
        Node* root = build(pre, 0, n-1, in,0, n-1, mpp );
        return root;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		
		int inorder[n], preorder[n];
		for(int i=0; i<n; i++)
			cin>> inorder[i];
		for(int i=0; i<n; i++)
			cin>> preorder[i];
		Solution obj;
		Node *root = obj.buildTree(inorder, preorder, n);
		printPostOrder(root);
		cout<< endl;
	}
}

// } Driver Code Ends