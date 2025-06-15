class Solution {
  public:
    vector<int> kLargest(vector<int>& arr, int k) {
        // Your code here
        priority_queue<int,vector<int>,greater<int>> pq;
        int size=0;
        int n= arr.size();
        for(int i=0;i<n;i++){
           
                pq.push(arr[i]);
               if(pq.size()>k){
                   pq.pop();
                   
               }
        }
        vector<int> v;
       while(!pq.empty()){
           v.push_back(pq.top());
           pq.pop();
       }
       reverse(v.begin(),v.end());
       return v;
    }
};