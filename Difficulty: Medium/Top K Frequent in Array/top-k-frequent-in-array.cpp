class Solution {
  public:
    vector<int> topKFrequent(vector<int> &arr, int k) {
        // Your code here
         unordered_map<int,int> mpp;
        for(int i=0;i<arr.size();i++){
            mpp[arr[i]]++;
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
          for(auto it : mpp){
            pq.push({it.second,it.first});
            if(pq.size()>k){
                pq.pop();
            }
          }

          vector<int> ans;
          while(!pq.empty()){
            auto it = pq.top();
            ans.push_back(it.second);
            pq.pop();
          }
          reverse(ans.begin(),ans.end());
          return ans;
    }
};
