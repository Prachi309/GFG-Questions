class Solution {
  public:
    vector<int> countLessEq(vector<int>& a, vector<int>& b) {
        // code here
           vector<int> cnt_arr(1e5+1,0);
        for(auto it:b){
            cnt_arr[it]++;
        }
        
        for(int i=1;i<=1e5;i++){
            cnt_arr[i] += cnt_arr[i-1];
        }
        
        vector<int> res;
        for(auto it:a){
            res.push_back(cnt_arr[it]);
        }
        return res;
    }
};