//{ Driver Code Starts
// C++ program to check if two strings are isomorphic


#include<bits/stdc++.h>


using namespace std;
#define MAX_CHARS 256

// } Driver Code Ends
class Solution
{
    public:
    //Function to check if two strings are isomorphic.
    bool areIsomorphic(string s, string t)
    {
        
        // Your code here
          if (s.length() != t.length()) return false;

    unordered_map<char, char> mapST, mapTS;

    for (int i = 0; i < s.length(); ++i) {
        char c1 = s[i];
        char c2 = t[i];

        // Check if there's a conflicting mapping
        if ((mapST.find(c1) != mapST.end() && mapST[c1] != c2) || 
    (mapTS.find(c2) != mapTS.end() && mapTS[c2] != c1)) {
            return false;
        }

        // Create the mapping
        mapST[c1] = c2;
        mapTS[c2] = c1;
    }

    return true;
        
    }
};

//{ Driver Code Starts.

// Driver program
int main()
{
    int t;
    cin>>t;
    string s1,s2;
    while (t--) {
        cin>>s1;
        cin>>s2;
        Solution obj;
        cout<<obj.areIsomorphic(s1,s2)<<endl;
    }
    
    return 0;
}
// } Driver Code Ends