class Solution {
  public:
   bool isValid(vector<int>& arr, int n, int k,long long maxTime){
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
    int splitArray(vector<int>& arr, int k) {
        // code here
         long long sum=0;
         int n= arr.size();
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