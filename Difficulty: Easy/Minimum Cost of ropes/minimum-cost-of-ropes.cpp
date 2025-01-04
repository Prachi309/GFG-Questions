//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to return the minimum cost of connecting the ropes.
    int minCost(vector<int>& arr) {
        // code here
        long long cost=0;
         priority_queue<long long, vector<long long>, greater<long long>> pq(arr.begin(), arr.end());

        while(pq.size()>1){
            long long rope= pq.top();
            pq.pop();
            rope+= pq.top();
            pq.pop();
            cost+=rope;
            pq.push(rope);
        }
        return cost;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        int num;
        vector<int> a;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            a.push_back(num);
        }
        Solution ob;
        cout << ob.minCost(a) << endl;
        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends