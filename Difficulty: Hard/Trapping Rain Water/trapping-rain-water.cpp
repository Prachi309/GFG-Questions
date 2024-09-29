//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {

    // Function to find the trapped water between the blocks.
  public:
    long long trappingWater(vector<int> &h) {
        // code here
        int n= h.size();
        long long l=0, r=n-1;
        long long lmax= 0, rmax=0, ans=0;
        while(l<=r){
            if(h[l]<= h[r]){
                if(h[l]>lmax){
                    lmax= h[l];
                }
                else{
                    ans+= lmax - h[l];
                }
                l++;
            }
            else{
                if(h[r]>rmax){
                    rmax=h[r];
                }
                else{
                    ans+= rmax-h[r];
                }
                r--;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    // testcases
    cin >> t;

    while (t--) {
        int n;

        // size of array
        cin >> n;

        vector<int> a(n);

        // adding elements to the array
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution obj;
        // calling trappingWater() function
        cout << obj.trappingWater(a) << endl;
    }

    return 0;
}
// } Driver Code Ends