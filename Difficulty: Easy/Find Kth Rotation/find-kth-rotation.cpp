//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    int findKRotation(vector<int> &nums) {
        // Code Here
     int n = nums.size();
        int low = 0, high = n - 1;
        
        // If the array is already sorted and not rotated
        if (nums[low] <= nums[high]) {
            return 0;
        }
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            // Check if mid element is the minimum (rotation point)
            if (mid > 0 && nums[mid] < nums[mid - 1]) {
                return mid;
            }
            
            // Check if mid+1 element is the minimum (rotation point)
            if (mid < n - 1 && nums[mid] > nums[mid + 1]) {
                return mid + 1;
            }
            
            // If the left part is sorted, the rotation must be in the right part
            if (nums[low] <= nums[mid]) {
                low = mid + 1;
            }
            // If the right part is sorted, the rotation must be in the left part
            else {
                high = mid - 1;
            }
        }
        
        return 0;
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input1;
        getline(cin, input1);
        stringstream ss1(input1);
        int number1;
        while (ss1 >> number1) {
            arr.push_back(number1);
        }
        Solution ob;
        int res = ob.findKRotation(arr);
        cout << res << endl;
    }
}
// } Driver Code Ends