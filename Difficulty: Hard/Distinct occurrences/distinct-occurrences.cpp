//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this method*/

class Solution {
    int f(int i,int j, string& s, string& t,vector<vector<int>>&dp){
        if(j<0) return 1;
        if(i<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==t[j]){
            return (dp[i][j]= f(i-1,j,s,t,dp)+ f(i-1,j-1,s,t,dp));
        } 
        else return dp[i][j]= f(i-1,j,s,t,dp);
        
    }
  public:
    int subsequenceCount(string& s, string& t) {
        // code here
        int n= s.size();
        int m= t.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        vector<double> prev(n+1,0);
        vector<double> curr(n+1,0);
        
        prev[0]=1;
        curr[0] = 1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1]==t[j-1]) curr[j]=prev[j]+prev[j-1];
                else curr[j]= prev[j];
            }
            prev= curr;
        }
        return (int)prev[m];
    }
};


//{ Driver Code Starts.

//  Driver code to check above method
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        string tt;
        cin >> s;
        cin >> tt;

        Solution ob;
        cout << ob.subsequenceCount(s, tt) << endl;

        cout << "~"
             << "\n";
    }
}
// } Driver Code Ends