//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
    bool isPos(vector<int>& nums, int th, int d){
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+= ceil((double)nums[i]/(double)d);
        }
        if(sum<=th) return true;
        return false;
    }
  public:
    int smallestDivisor(vector<int>& nums, int K) {

        // Write your code here.
        int maxi=INT_MIN;
        for(int i=0;i<nums.size();i++){
            maxi=max(maxi,nums[i]);
           
        }
        int ans=0;
        int low= 1, high=maxi;
  
        while(low<=high){
            int mid=(low+high)/2;
            if(isPos(nums,K,mid)){
                ans=mid;
                high=mid-1;
                
            }
            else{
                low=mid+1;
                
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input
        int n, k;
        cin >> n >> k;
        vector<int> vec(n);
        for (int i = 0; i < n; i++) cin >> vec[i];

        Solution obj;
        cout << obj.smallestDivisor(vec, k) << endl;
        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends