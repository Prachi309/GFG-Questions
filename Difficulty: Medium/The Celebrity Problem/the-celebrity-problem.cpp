class Solution {
  public:
    int celebrity(vector<vector<int> >& mat) {
        // code here
        int top=0;
        int down= mat.size()-1;
        int n= mat.size();
        
        while(top<down){
            if(mat[top][down]==1){
                top++;
                
            }
            else if(mat[down][top]==1){
              down--;
                
            }
            else {
                top++;
                down--;
            }
        }
        if(top>down) return -1;
        else{
        for(int i=0;i<n;i++){
            if(i==top) continue;
            if(mat[top][i]==0 && mat[i][top]==1);
            else return -1;
        }
        }
        return top;
    }
};