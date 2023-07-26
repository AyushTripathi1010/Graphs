class Solution {
  public:
    // Function to find the number of islands.
    int n, m;
    void dfs(int row, int col,vector<vector<int>>&vis, vector<vector<char>>& grid, int *delrow, int *delcol)
    {
        vis[row][col] = 1;
        
        for(int i =0 ; i < 8 ; i++)
        {
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];
            
            if(nrow >=0 && nrow < n && ncol>=0 && ncol<m && !vis[nrow][ncol] && grid[nrow][ncol] == '1')
            {
                dfs(nrow, ncol , vis , grid , delrow, delcol);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        
         n = grid.size();
         m = grid[0].size();
        int delrow[] = {0, 1,1,1,0,-1,-1,-1};
        int delcol[] ={1, 1,0,-1,-1,-1,0,1};
        
        vector<vector<int>> vis(n , vector<int> (m , 0));
        int cnt= 0;
        for(int i=  0; i < n ; i++)
        {
            for(int j = 0 ; j< m ;j++)
            {
                if(!vis[i][j] && grid[i][j] == '1')
                {
                    dfs(i, j, vis , grid, delrow, delcol);
                    cnt++;
                }
            }
        }
        
        return cnt;
    
    }
};