//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template in C++

class Solution {
  public:
    // Function to find minimum number of pages.
    int countStu(int n,int arr[], int m){
        
        int stu=1;
        long long pagesHeld=0;
        for(int i=0;i<n;i++){
             if (pagesHeld + arr[i] > m) {
                stu++;                // Increment the student count
                pagesHeld = arr[i];   // Start new student with current book's pages
                // If a single book has pages > maxPages, more students than allowed
                if (arr[i] > m )return INT_MAX; 
            } else {
                pagesHeld += arr[i];  // Add pages to current student’s total
            }
            
            
        }
        return stu;
    }
    
    
    long long findPages(int n, int arr[], int m) {
        if(m>n) return -1;
        // code here
       int low=arr[0];
        long long high=0;
        
        for(int i=0;i<n;i++){
            low= max(low,arr[i]);
            high+=arr[i];
        }
        
        while(low<=high){
            int mid = low + (high - low) / 2; 
            int stu= countStu(n,arr,mid);
            if(stu>m){
                low=mid+1;
            }
          
            else{
                high=mid-1;
            }
        }
        return low;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int A[n];
        for (int i = 0; i < n; i++) {
            cin >> A[i];
        }
        int m;
        cin >> m;
        Solution ob;
        cout << ob.findPages(n, A, m) << endl << "~\n";
    }
    return 0;
}

// } Driver Code Ends