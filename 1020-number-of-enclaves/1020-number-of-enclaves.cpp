class Solution {
    private:
     void dfs(int row, int col, vector<vector<int>> &grid,vector<vector<int>> &vis, int delrow[], int delcol[]) {
        vis[row][col] = 1; 
        int n = grid.size();
        int m = grid[0].size();
        
        // check for top, right, bottom, left 
        for(int i = 0;i<4;i++) {
            int nrow = row + delrow[i];
            int ncol = col + delcol[i]; 
            // check for valid coordinates and unvisited Os
            if(nrow >=0 && nrow <n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && grid[nrow][ncol] == 1) {
                dfs(nrow, ncol, grid, vis, delrow, delcol); 
            }
        }
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        
        vector<vector<int>>vis(n,vector<int>(m,0));
        int delrow[4]={-1,0,1,0};
        int delcol[4]={0,1,0,-1};
        
          //dfs call for first row and last row
        for(int j = 0 ; j<m;j++) {
            // check for unvisited Os in the boundary rows
            // first row 
            if(!vis[0][j] && grid[0][j] == 1) {
                dfs(0, j, grid, vis, delrow, delcol); 
            }
           
            //last row
            if(!vis[n-1][j] && grid[n-1][j] == 1) {
                dfs(n-1, j, grid, vis, delrow, delcol); 
            }
        }
        
        //dfs for first col and last col
        for(int i = 0 ; i<n;i++) {
            // check for unvisited Os in the boundary rows
            // first col
            if(!vis[i][0] && grid[i][0] == 1) {
                dfs(i, 0, grid, vis, delrow, delcol); 
            }
           
           // last column
            if(!vis[i][m-1] && grid[i][m-1] == 1) {
                dfs(i, m-1, grid, vis, delrow, delcol); 
            }
        }
        
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j]&& grid[i][j]==1){
                    // board[i][j]='X';
                    cnt++;
                }
            }
        }
        return cnt;
    }
};