//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    // Function to find the minimum number of elements to be removed.
    int minRemoval(vector<int>& arr) {
        // code here
         int ans=INT_MAX;
        int c=0;
        int n= arr.size();
        sort(arr.begin(),arr.end());
        for(int i=0;i<n;i++){
            int l=0,r=n-1;
            int t=2*arr[i]+1;
            
            while(l<=r){
                int m=(l+r)/2;
                
                if(arr[m]>=t)
                    r=m-1;
                else
                    l=m+1;
            }
            
            ans=min(ans,n-(r-i+1));
            
        }
        return(ans);
        
    }
};

//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);

    while (t--) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        vector<int> nums;
        int num;
        while (ss >> num) {
            nums.push_back(num);
        }
        Solution ob;
        cout << ob.minRemoval(nums) << endl;
    }
    return 0;
}

// } Driver Code Ends