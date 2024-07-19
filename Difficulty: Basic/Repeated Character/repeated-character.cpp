//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

const int CHAR=256;
class Solution
{
  public:
     char firstRep(string s) {
        bool vis[CHAR] = {false};
       char res = '#';
        for (int i = s.size() - 1; i >= 0; i--) {
            if (vis[s[i]]) {
                res = s[i];
            } else {
                vis[s[i]] = true;
            }
        }
        return res;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        char res = ob.firstRep (s);
        if (res == '#') cout << -1 << endl;
        else cout << res << endl;
    }
    return 0;
}



// } Driver Code Ends