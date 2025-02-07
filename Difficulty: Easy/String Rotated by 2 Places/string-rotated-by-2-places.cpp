//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to check if a string can be obtained by rotating
    // another string by exactly 2 places.
    void rotateClock(string &s1){
       if(s1.size()<2) return ;
        reverse(s1.begin(),s1.begin()+2);
        reverse(s1.begin()+2,s1.end());
        reverse(s1.begin(),s1.end());
        
    }
    void rotateAntiClock(string &s1){
        if(s1.size()<2) return ;
        reverse(s1.begin(),s1.begin()+s1.size()-2);
        reverse(s1.begin()+s1.size()-2,s1.end());
        reverse(s1.begin(),s1.end());
        
    }
    bool isRotated(string& s1, string& s2) {
        // Your code here
          if (s1.size() != s2.size()) return false;  // Strings of different lengths can't be rotations
        if(s1.size()<2) return s1==s2;
        string s = s1;
        rotateClock(s);
        if (s == s2) return true;
        
        s = s1;
        rotateAntiClock(s);
        if (s == s2) return true;
        return false;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string s;
        string b;
        cin >> s >> b;
        cin.ignore();
        Solution obj;
        cout << (obj.isRotated(s, b) == 0 ? "false" : "true") << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends