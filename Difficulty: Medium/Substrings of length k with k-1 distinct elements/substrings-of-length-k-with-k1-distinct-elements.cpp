class Solution {
  public:
    int substrCount(string &s, int k) {
        // code here
         int n=s.size();
    unordered_map<char,int>mpp;
    
    int i=0;
    int j=0;
    int cnt=0;

    while(j<n){
        
        mpp[s[j]]++;
        if(j-i+1==k && mpp.size()==k-1){
            
            cnt++;
        }
       while(i<=j&& (j-i+1==k) || mpp.size()>=k){
     
           mpp[s[i]]--;
           if(mpp[s[i]]==0){
               mpp.erase(s[i]);
           }
            i++;
        }
    
        j++;
    }
    
    return cnt;
    
    }
};