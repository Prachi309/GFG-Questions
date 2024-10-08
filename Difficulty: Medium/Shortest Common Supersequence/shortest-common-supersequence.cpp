//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++


class Solution
{
    public:
    //Function to find length of shortest common supersequence of two strings.
    int shortestCommonSupersequence(string s, string t, int n, int m)
    {
        //code here
     
        vector<vector<int>>dp(n+1,vector<int> (m+1,0));
        
        for(int i=0 ;i<=n;i++) dp[i][0]=0;
        for(int j=0 ;j<=m;j++) dp[0][j]=0;
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1]==t[j-1]) dp[i][j] = 1+ dp[i-1][j-1];
                else{
                    dp[i][j]= max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        
        return n+m- dp[n][m];
       
        // string ans= "";
     
        
      
        // int i=n, j=m;
        // while(i>0 && j>0){
            
        //     if(s[i-1]==t[j-1]){
        //         ans+=s[i-1];
               
        //         i--;
        //         j--;
        //     }
        //     else if(dp[i-1][j]>dp[i][j-1]){
        //         ans+=s[i-1];
        //         i--;
              
        //     }
        //     else{
        //           ans+=t[j-1];
        //         j--;
              
        //     }
            
        // }
        // while(i>0){
        //     ans+=s[i-1];
        //     i--;
        // }
        
        // while(j>0){
        //     ans+=t[j-1];
        //     j--;
        // }
        // reverse(ans.begin(),ans.end());
        
        
        // return ans;
    }
};

//{ Driver Code Starts.

int main()
{   
    
    int t;
    
    //taking total testcases
    cin >> t;
    while(t--){
    string X, Y;
    //taking String X and Y
	cin >> X >> Y;
	
	//calling function shortestCommonSupersequence()
	Solution obj;
	cout << obj.shortestCommonSupersequence(X, Y, X.size(), Y.size())<< endl;
    }
	return 0;
}


// } Driver Code Ends