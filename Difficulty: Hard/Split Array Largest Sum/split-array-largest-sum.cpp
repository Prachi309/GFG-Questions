//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  
  bool isValid(int arr[], int n, int k,long long maxTime){
        int p=1;
        long long time=0;
        for(int i=0;i<n;i++)
        {
            if(time + arr[i] <= maxTime){
                time+=arr[i];
            }
            else{
                time=arr[i];
                p++;
            }
        }
        return p <= k ? true : false;
    }
    
    int splitArray(int arr[] ,int n, int k) {
        // code here
         long long sum=0;
        long long low=LONG_MIN,high;
        for(int i=0;i<n;i++)
        {
            sum+=arr[i];
            low=max(low,(long long)arr[i]);
        }
        long long ans=-1;
        high=sum;
        while(low <= high)
        {
            long long mid = low+(high - low)/2;
            if(isValid(arr,n,k,mid)){
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
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
        int N, K;
        
        cin>>N>>K;
        int arr[N];
        
        for(int i=0 ; i<N ; i++)
            cin>>arr[i];

        Solution ob;
        cout<<ob.splitArray(arr,N,K);
        cout<<"\n";
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends