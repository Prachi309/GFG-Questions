//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

const int mod= 1e9+7;
class Solution
{
  
    public:
    //Function to count number of ways to reach the nth stair.
    int countWays(int n)
    {
        // your code here
        if (n == 0 || n == 1) return 1;

        long long prev2 = 1; // equivalent to dp[0]
        long long prev1 = 1; // equivalent to dp[1]
        
        for(int i = 2; i <= n; i++) {
           long long curr = (prev1 + prev2) % mod;
            prev2 = prev1;
            prev1 = curr;
        }
        
        return prev1;
    }
};



//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking stair count
        int m;
        cin>>m;
        Solution ob;
        cout<<ob.countWays(m)<<endl; // Print the output from our pre computed array
    }
    return 0;
}

// } Driver Code Ends