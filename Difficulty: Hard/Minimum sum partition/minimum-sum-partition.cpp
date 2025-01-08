//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {

  public:
    int minDifference(vector<int>& nums) {
        // Your code goes here
        int total=0;
        for(auto it: nums){
            total+=it;
        }
        int k= total;
        int n= nums.size();
        vector<bool> prev(k+1,0);
        vector<bool> curr(k+1,0);
        prev[0]=curr[0]=1;
    
    if (nums[0] <= k) {
        prev[nums[0]] = true; 
    }
        for(int i=1;i<n;i++){
            for(int target=1;target<=k;target++){
                bool nottake= prev[target];
                bool take= false;
                if(nums[i]<=target) take= prev[target-nums[i]];
                curr[target]= take|nottake;
            }
            prev=curr;
        }
        int mini=INT_MAX;
        for(int s1=0;s1<= total/2 ; s1++){
            if(prev[s1]){
             
                mini= min(mini,abs(total-s1-s1));
            }
        }
        return mini;
    }
};


//{ Driver Code Starts.
int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {

        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int ans = ob.minDifference(arr);

        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends