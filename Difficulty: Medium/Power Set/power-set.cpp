//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
   void printS(int i, int n, string &s, string current, vector<string> &result) {
        if (i == n) {
            if (!current.empty()) {
                result.push_back(current);
            }
            return;
        }

        // Include the current character
        printS(i + 1, n, s, current + s[i], result);
        
        // Exclude the current character
        printS(i + 1, n, s, current, result);
    }
    
public:
    vector<string> AllPossibleStrings(string s) {
        vector<string> result;
        printS(0, s.size(), s, "", result);
        
     
        sort(result.begin(), result.end());
        
        return result;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		Solution ob;
		vector<string> res = ob.AllPossibleStrings(s);
		for(auto i : res)
			cout << i <<" ";
		cout << "\n";

	}
	return 0;
}
// } Driver Code Ends