class Solution {
  public:
    vector<int> findUnion(vector<int>& a, vector<int>& b) {
        // code here
        vector<int> v;
          sort(a.begin(), a.end());
    sort(b.begin(), b.end());

        int n= a.size();
    int m=b.size();
        int i=0;
        int j=0;
        while(i<n && j<m){
            if (a[i] < b[j]) {
            if (v.empty() || v.back() != a[i]) v.push_back(a[i]);
            i++;
        } else if (a[i] > b[j]) {
            if (v.empty() || v.back() != b[j]) v.push_back(b[j]);
            j++;
        } else { 
            if (v.empty() || v.back() != a[i]) v.push_back(a[i]);
            i++;
            j++;
        }
        }
        while(i<n){
             if(v.size()==0 || v.back()!=a[i]){
                    v.push_back(a[i]);
                    
                }
                i++;
        }
        while(j<m){
             if(v.size()==0 || v.back()!=b[j]){
                    v.push_back(b[j]);
                   
                }
                 j++;
        }
        return v;
    }
};