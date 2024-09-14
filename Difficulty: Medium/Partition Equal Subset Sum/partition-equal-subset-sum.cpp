//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
bool isSubsetSum(int n, int arr[], long long k) {
        vector<bool> prev(k + 1, 0), curr(k + 1, 0);
        
        prev[0] = curr[0] = true;
        if (arr[0] <= k)
            prev[arr[0]] = true;
        
        for (int ind = 1; ind < n; ind++) {
            for (int t = 1; t <= k; t++) {
                bool nottake = prev[t];
                bool take = false;
                
                if (arr[ind] <= t) {
                    take = prev[t - arr[ind]];
                }
                curr[t] = take | nottake;
            }  
            prev = curr;
        }
        return prev[k];
    }

    int equalPartition(int n, int arr[]) {
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            sum += arr[i];
        }
        if (sum % 2) return 0;  
        long long target = sum / 2;
        
        return isSubsetSum(n, arr, target);
    
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends