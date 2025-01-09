//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  int f(int ind,vector<int>& arr, int t, vector<vector<int>>& dp){
      if(t==0) return 1;
      if(ind==0) return arr[ind]==t;
      if(dp[ind][t]!=-1) return dp[ind][t];
      else{
          int nottake=f(ind-1,arr,t,dp);
          int take=0;
          if(arr[ind]<=t){
              take= f(ind-1,arr,t-arr[ind],dp);
          }
          return dp[ind][t]=take+nottake;
      }
  }
    int perfectSum(vector<int>& arr, int target) {
        // code here
        int n= arr.size();
       const int MOD = 1e9 + 7;
        vector<int> prev(target+1,0);
        vector<int> curr(target+1,0);
       for (int tar = 0; tar <= target; tar++)
        {
            if (tar == 0 && arr[0] == 0)
                prev[tar] = 2;
            else if (tar == 0 || tar == arr[0])
                prev[tar] = 1;
            else
                prev[tar] = 0;
        }
        
        for(int ind=1;ind<n;ind++){
            for(int t=0;t<=target;t++){
                int nottake=prev[t];
                int take=0;
                if (arr[ind]<=t){
                take= prev[t-arr[ind]];
                }
                curr[t]= (take+nottake)%MOD ;
            }
            prev=curr;
        }
        return prev[target];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore newline character after t

    while (t--) {
        vector<int> arr;
        int target;
        string inputLine;

        getline(cin, inputLine); // Read the array input as a line
        stringstream ss(inputLine);
        int value;
        while (ss >> value) {
            arr.push_back(value);
        }

        cin >> target;
        cin.ignore(); // Ignore newline character after target input

        Solution solution;
        cout << solution.perfectSum(arr, target);
        cout << "\n~\n";
    }

    return 0;
}

// } Driver Code Ends