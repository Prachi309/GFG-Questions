//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:

    string longestCommonPrefix(vector<string> arr) {
        // your code here
        string res="";
        sort(arr.begin(),arr.end());
        string start=arr[0];
        string end=arr[arr.size()-1];
        
        for(int i=0;i<start.size();i++){
            if(start[i]==end[i]) res+= start[i];
            
            else{
                break;
            }
            
            
        }
    if(res.size()==0){
        res+="-1";
    }
   return res;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<string> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        string number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        cout << ob.longestCommonPrefix(arr) << endl;
    }
}

// } Driver Code Ends