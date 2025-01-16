//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to find the number of islands.
     void dfs(int i,int j, vector<vector<char>>& grid, vector<vector<int>>& vis,int n, int m) {
        vis[i][j] = 1;
        
        for(int delrow=-1;delrow<=1;delrow++){
            for(int delcol=-1;delcol<=1;delcol++){
                int nrow= i+delrow;
                int ncol= j+delcol;
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]=='1' && !vis[nrow][ncol]){
                    dfs(nrow,ncol, grid,vis,n,m);
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int n= grid.size();
        int m= grid[0].size();
       int count=0;
        vector<vector<int>>vis(n,vector<int>(m,0)) ;
        
        for (int i = 0; i < n; i++) {
            for(int j=0;j<m;j++){
            if (!vis[i][j]&& grid[i][j]=='1') {
                count++;
                dfs(i,j, grid, vis,n,m);
            }
            }
        }
        
        return count;
        
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends