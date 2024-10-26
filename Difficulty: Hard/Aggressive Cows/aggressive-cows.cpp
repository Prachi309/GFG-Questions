//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    bool canWeplace(vector<int> &stalls,int d, int k,int n){
        int cnt=1, last=stalls[0];
        for(int i=1;i<n;i++){
            if(stalls[i]-last >=d){
                cnt++;
                last= stalls[i];
                if(cnt>=k) return true;
            }
        }
        return false;
        
    }
    
    int solve(vector<int> &stalls, int k) {

        // Write your code here
        sort(stalls.begin(),stalls.end());
        int n= stalls.size();
        int low=1;
        int high= stalls[n-1]- stalls[0];
        
        while(low<=high){
            
            int mid=(low+high)/2;
            
            if(canWeplace(stalls, mid, k,n)){
                low= mid+1;
                
            }
            
            else{
                high=mid-1;
            }
            
        }
        return high;
    }
};

//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int k;
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string in;
        getline(cin, in);
        stringstream sss(in);
        int num;
        while (sss >> num) {
            k = num;
        }
        Solution ob;
        int ans = ob.solve(arr, k);
        cout << ans << endl;
    }
    return 0;
}

// } Driver Code Ends