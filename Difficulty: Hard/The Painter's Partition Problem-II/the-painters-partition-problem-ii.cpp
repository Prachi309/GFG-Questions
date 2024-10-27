//{ Driver Code Starts
// driver code

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
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
    
    
   
    long long minTime(int arr[], int n, int k)
    {
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

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int k,n;
		cin>>k>>n;
		
		int arr[n];
		for(int i=0;i<n;i++)
		    cin>>arr[i];
		Solution obj;
		cout << obj.minTime(arr, n, k) << endl;
	
cout << "~" << "\n";
}
	return 0;
}
// } Driver Code Ends