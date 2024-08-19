//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int minimumEnergy(vector<int>& height, int n) {
        // Code here
        if (n == 1) return 0;  // No energy needed if there's only one stair

        int prev = 0, prev1 = 0;

        for (int i = 1; i < n; i++) {
            int fs = prev + abs(height[i] - height[i - 1]);  // Step from i-1 to i
            int ss = INT_MAX;

            if (i > 1) {
                ss = prev1 + abs(height[i] - height[i - 2]);  // Step from i-2 to i
            }

            int cur = min(fs, ss);  =
            prev1 = prev; 
            prev = cur;
        }

        return prev;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimumEnergy(arr, N) << "\n";
    }
    return 0;
}
// } Driver Code Ends