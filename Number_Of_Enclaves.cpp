
class Solution {
  public:
    int numberOfEnclaves(vector<vector<int>> &grid) {
        // Code here
        
        int n = grid.size();
        int m = grid[0].size();
        int delrow[] = {0, 1, 0, -1};
         int delcol[] = {1, 0, -1, 0};
        vector<vector<int>> vis(n , vector<int> (m , 0));
        int cnt =0;
        queue<pair<int,int>> q;
        
        // First Row
        for(int i= 0 ; i < m ; i++)
        {
            if(grid[0][i] == 1)
            {
                q.push({0, i});
                vis[0][i] = 1;
            }
            
        }
        
        // Last Row
        for(int i= 0 ; i < m ; i++)
        {
            if(grid[n-1][i] == 1)
            {
                 q.push({n-1, i});
                 vis[n-1][i] = 1;
                 
            }
            
        }
        
        // First Column
        for(int i= 0 ; i < n ; i++)
        {
            if(grid[i][0] == 1 )
            {
                 q.push({i, 0});
                 vis[i][0] = 1;
            }
            
        }
        
        // Second Column
        for(int i= 0 ; i < n ; i++)
        {
            if(grid[i][m-1] == 1 )
            {
                 q.push({i, m-1});
                 vis[i][m-1] = 1;
            }
            
        }
        
        while(!q.empty())
        {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            
            for(int i =0 ; i < 4 ; i++)
            {
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];
                
                if(nrow >=0 && nrow < n && ncol>=0 && ncol <m && !vis[nrow][ncol] && grid[nrow][ncol] == 1)
                {
                    q.push({nrow, ncol});
                    vis[nrow][ncol] = 1;
                }
            }
        }
        
        for(int i =0 ; i < n ; i++)
        {
            for(int j = 0 ; j < m ; j++)
            {
                 if(grid[i][j] == 1 && !vis[i][j])
                 cnt++;
            }
        }
        
        return cnt;
    }
};