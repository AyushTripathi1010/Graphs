// User function Template for C++

class Solution {
  public:
    void dfs(int row, int col, vector<pair<int,int>>&vec, vector<vector<int>>&vis, vector<vector<int>>&grid, int brow, int bcol, int *delrow,int *delcol)
    {
        vis[row][col] = 1;
        
        vec.push_back({row - brow , col - bcol});
        
        for(int i= 0 ; i < 4 ; i++)
        {
            int nrow = row + delrow[i];
            int ncol  = col + delcol[i];
            
            if(nrow>=0 && nrow< grid.size() && ncol >= 0 && ncol<grid[0].size() && !vis[nrow][ncol] && grid[nrow][ncol] == 1)
            {
                dfs(nrow, ncol, vec , vis, grid, brow, bcol, delrow, delcol);
            }
        }
    }
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> vis(n , vector<int> (m , 0));
        int delrow[] = {0 , 1, 0, -1};
        int delcol[] = {1, 0 , -1, 0};
        set<vector<pair<int, int>>> s;
        
        for(int i= 0  ; i  < n ; i++)
        {
            for(int j = 0; j < m ; j++)
            {
                if(grid[i][j] == 1 && !vis[i][j])
                {
                    vector<pair<int,int>> v;
                    dfs(i, j,v , vis, grid, i, j, delrow, delcol);
                    s.insert(v);
                }
            }
        }
        
        return s.size();
    }
};