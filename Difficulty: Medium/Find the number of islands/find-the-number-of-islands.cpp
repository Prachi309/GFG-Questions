//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  public:
    // Function to find the number of islands.
    
    void bfs(int i, int j, vector<vector<char>>& grid, 
    vector<vector<int>>&vis){
        queue<pair<int,int>> q;
        q.push({i,j});
        int n = grid.size(), m= grid[0].size();
        while(!q.empty()){
            auto it = q.front();
            int row= it.first;
            int col= it.second;
            q.pop();
            
            for(int r= -1 ; r<=1; r++ ){
                for(int c=-1;c<=1;c++){
                    int nrow= row+r;
                    int ncol = col+c;
                    if(nrow>=0 && nrow<n &&ncol>=0 && ncol<m && !vis[nrow][ncol]
                    && grid[nrow][ncol]=='1'){
                        vis[nrow][ncol]=1;
                        q.push({nrow,ncol});
                    }
                    
                    
                }
            }
        }
        
    }
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int n= grid.size();
        int m= grid[0].size();
       vector<vector<int>>vis(n, vector<int>(m,0));
       int cnt=0;
       
       for(int i=0;i<n;i++){
           for(int j=0;j<m;j++){
               if(!vis[i][j] && grid[i][j]=='1'){
                   cnt++;
                   bfs(i,j,grid,vis);
               }
           }
       }
       return cnt;
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