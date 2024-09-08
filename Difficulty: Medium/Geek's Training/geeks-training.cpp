//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int maximumPoints(vector<vector<int>>& arr, int n) {
        // Code here
        vector<int>prev(4,0);
       prev[0] = max(arr[0][1], arr[0][2]); // If task 0 is not chosen on day 1
        prev[1] = max(arr[0][0], arr[0][2]); // If task 1 is not chosen on day 1
        prev[2] = max(arr[0][0], arr[0][1]); // If task 2 is not chosen on day 1
        prev[3] = max(arr[0][0], max(arr[0][1], arr[0][2])); // If no restriction on last task

        // Iterating over the rest of the days
        for (int day = 1; day < n; day++) {
            vector<int> temp(4, 0); // Temp array for the current day's calculations
            
            for (int last = 0; last < 4; last++) {
                temp[last] = 0;
                for (int task = 0; task < 3; task++) {
                    if (task != last) {
                        temp[last] = max(temp[last], arr[day][task] + prev[task]);
                    }
                }
            }
            prev = temp; // Move current day's results to the previous day
        }
        return prev[3]; 
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> arr;
        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            arr.push_back(temp);
        }

        Solution obj;
        cout << obj.maximumPoints(arr, n) << endl;
    }
    return 0;
}
// } Driver Code Ends