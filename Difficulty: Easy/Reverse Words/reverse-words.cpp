//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string S) 
    { 
        // code here 
        reverse(S.begin(),S.end());
        
        int start=0;
        for(int end=0;end<=S.size();end++){
            if(end==S.size() || S[end]=='.'){
                reverse(S.begin()+start, S.begin()+end);
                start= end+1;
            }
           
            
        }
        return S;
    } 
};

//{ Driver Code Starts.
int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        string s;
        cin >> s;
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
}
// } Driver Code Ends