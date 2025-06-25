

class Solution {
  public:
    // Function to search a given number in row-column sorted matrix.
    bool searchMatrix(vector<vector<int>> &mat, int x) {
        // code here
          int n= mat.size(),m=mat[0].size();
        int row=0 ,col=m-1;

        while(row< n && col>=0){
            if(mat[row][col]==x){
                return true;
            }
            else if(mat[row][col]< x) row++;
            else col--;
        }
        return false;
    }
};