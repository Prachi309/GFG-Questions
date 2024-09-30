//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(vector<long long> &heights) {
        // Your code here
        
        long long maxi=0;
        stack<long long>st;
        for(int i=0;i<heights.size();i++){
            while(!st.empty() && heights[ st.top() ] > heights[i]){
                int index= st.top();
                st.pop();
                int nse= i;
                int pse= st.empty()? -1 : st.top();
                maxi= max(maxi, (heights[index]* (nse - pse -1)));

            }
            st.push(i);
        }

        while(!st.empty()){
           int nse= heights.size();
            int index= st.top();
            st.pop();
           int pse = st.empty()? -1 : st.top();

           maxi= max (maxi, (heights[index] * (nse-pse -1)));
        }
        return maxi;

    }
};


//{ Driver Code Starts.

int main() {
    long long t;

    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<long long> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        Solution ob;
        cout << ob.getMaxArea(arr) << endl;
    }
    return 0;
}

// } Driver Code Ends