//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		

	public:
	int lcs(int n, int m, string s, string t) {
        // your code here
        vector<int> prev(m+1,0),curr(m+1,0);
        for(int j=0;j<=m;j++){
            prev[j]=0;
        }
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1]==t[j-1]) curr[j]=1+prev[j-1];
                else{
                    curr[j]= max(prev[j],curr[j-1]);
                }
            }
            prev=curr;
        }
        return prev[m];
    }
	int minOperations(string str1, string str2) 
	{ 
	    // Your code goes here
	         return str1.size()+str2.size()- 2* lcs(str1.size(),str2.size(),str1,str2);
	    
	} 
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;

	    Solution ob;
	    cout << ob.minOperations(s1, s2) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends