//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to compute the edit distance between two strings
    int editDistance(string& s, string& t) {
        // code here
        int n= s.size();
        int m= t.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for(int i=0;i<=n;i++) dp[i][0]= i;
        for(int j=0;j<=m;j++) dp[0][j]=j;

         for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++) {
                if(s[i-1]==t[j-1]) dp[i][j]= dp[i-1][j-1];
            else {
            int del = 1+dp[i-1][j];
            int replace = 1+dp[i-1][j-1];
            int insert = 1 + dp[i][j-1];
            dp[i][j] = min({del, replace, insert});

            }
            }
         }

        return dp[n][m];
    }
};

//{ Driver Code Starts.

int main() {

    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        string s1;
        getline(cin, s1);
        string s2;
        getline(cin, s2);
        Solution ob;
        int ans = ob.editDistance(s1, s2);
        cout << ans << "\n";
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends