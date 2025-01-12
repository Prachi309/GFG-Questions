//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    // Function to find length of longest increasing subsequence.
    int lis(vector<int>& arr) {
        // code here
        int n= arr.size();
        vector<int> ahead(n+1,0);
        vector<int> curr(n+1,0);
        
        for(int ind=n-1;ind>=0;ind--){
            for(int prev= ind-1;prev>=-1;prev--){
                int len= 0+ahead[prev+1];
                if(prev==-1 || arr[ind]>arr[prev]){
                    len= max(len,1+ ahead[ind+1]);
                }
                curr[prev+1]= len;
            }
            ahead=curr;
        }
        return ahead[0];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // to ignore the newline after the integer input

    while (t--) {
        int n;
        vector<int> arr;
        string input;

        // Input format: first number n followed by the array elements
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            arr.push_back(num);

        Solution obj;
        cout << obj.lis(arr) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends