class Solution {
  public:
  
    int largestHist(vector<int>& heights){
         int n = heights.size();
      stack < int > st;
      int leftsmall[n], rightsmall[n];
      for (int i = 0; i < n; i++) {
        while (!st.empty() && heights[st.top()] >= heights[i]) {
          st.pop();
        }
        if (st.empty())
          leftsmall[i] = 0;
        else
          leftsmall[i] = st.top() + 1;
        st.push(i);
      }
      while (!st.empty())
        st.pop();

      for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && heights[st.top()] >= heights[i])
          st.pop();

        if (st.empty())
          rightsmall[i] = n - 1;
        else
          rightsmall[i] = st.top() - 1;

        st.push(i);
      }
      int maxA = 0;
      for (int i = 0; i < n; i++) {
        maxA = max(maxA, heights[i] * (rightsmall[i] - leftsmall[i] + 1));
      }
      return maxA;
        
    }
    int maxArea(vector<vector<int>> &mat) {
        // code here
        int n= mat.size(),m=mat[0].size();
        int maxArea=0;
        vector<vector<int>> pse(n,vector<int>(m,0));
        for(int j=0;j<m;j++){
            int sum=0;
            for(int i=0;i<n;i++){
                sum+=mat[i][j];
                if(mat[i][j]==0) sum=0;
                pse[i][j]=sum;
            }
        }
        
        for(int i=0;i<n;i++){
            maxArea= max(maxArea,largestHist(pse[i]));
        }
        return maxArea;
    }
};