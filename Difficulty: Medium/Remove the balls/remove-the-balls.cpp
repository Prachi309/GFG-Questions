class Solution {
  public:
    int findLength(vector<int> &color, vector<int> &radius) {
        // code here
          stack<int> st;
        
        int n = color.size();
        
        for(int i = 0;i<n;i++){
            if(!st.empty()){
                int t = st.top();
                if(color[t] == color[i] && radius[i] == radius[t]){
                    st.pop();
                }else{
                    st.push(i);
                }
            }else{
                st.push(i);
            }
        }
        
        return st.size();
    }
};