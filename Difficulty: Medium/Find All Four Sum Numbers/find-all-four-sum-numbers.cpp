//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int> > fourSum(vector<int> &nums, int target) {
        // Your code goes here
         int n= nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        
        for(int i=0;i<n;i++){
            if(i>0 && nums[i]==nums[i-1]){continue;}
            for(int j=i+1;j<n;j++){
            if(j!=i+1 && nums[j]==nums[j-1]){continue;}
                int k=j+1, l=n-1;
            while(k<l){
                long long sum =nums[i];
                sum+=nums[j];
                sum+=nums[k];
                sum+=nums[l];
                if(sum==target){
                    vector<int> temp= {nums[i],nums[j],nums[k],nums[l]};
                    k++;l--;
                    ans.push_back(temp);
                    while(k<l && nums[k]==nums[k-1])k++;
                    while(k<l&& nums[l]==nums[l+1])l--;
                }
                else if(sum<target) k++;
                else{
                    l--;
                }
            }
        }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.fourSum(a, k);
        for (auto &v : ans) {
            for (int &u : v) {
                cout << u << " ";
            }
            cout << "$";
        }
        if (ans.empty()) {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends