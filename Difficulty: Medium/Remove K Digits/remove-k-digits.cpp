//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    string removeKdigits(string nums, int k) {
        stack<int> st;
        int n= nums.size();
        for(int i=0 ;i<n;i++){
            while(!st.empty() && k!=0 &&  st.top()- '0' > nums[i]- '0'){
                st.pop();
                k--;
            }
            st.push(nums[i]);
        }
        while(k > 0) 
        {
            st.pop();
            k--;
        }       
        if(st.empty()) return  "0";
        
        
        string res = "";
        
        while(!st.empty()){
            res+=st.top();
            st.pop();
        }
        
        while(res.size()!=0 && res.back()=='0'){
            res.pop_back();
        }
        reverse(res.begin(), res.end());
        
        if(res.size()==0) return "0";
        
        else return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        int K;
        cin >> K;
        Solution obj;
        cout << obj.removeKdigits(S, K) << endl;
    }
    return 0;
}

// } Driver Code Ends