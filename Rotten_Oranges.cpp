class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
        int n, m;
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        
        n = grid.size();
        m = grid[0].size();
        
         int delrow[] = {0, 1, 0, -1};
         int delcol[] = {1, 0, -1, 0};
         
         int distance =-1 ;
         
         queue<pair<pair<int,int>, int>> q; // row, col, dist
         
         for(int i = 0; i < n ; i++)
         {
              for(int j = 0; j < m ; j++)
              {
                  if(grid[i][j] == 2)
                  q.push({{i, j}, 0});
              }
         }
         
         while(!q.empty())
         {
             
                 int row = q.front().first.first;
                 int col = q.front().first.second;
                 int dist= q.front().second;
                 distance = max(distance, dist);
                  
                 q.pop();
                 
                 for(int i = 0; i<4 ; i++)
                 {
                     int nrow = row + delrow[i];
                     int ncol = col + delcol[i];
                     
                     if(nrow >=0 && nrow < n && ncol>=0 && ncol<m && grid[nrow][ncol] == 1)
                     {
                           q.push({{nrow,ncol}, distance+1});
                           grid[nrow][ncol] = 2;
                     }
                 }
         }
                
                for(int i= 0 ; i < n ; i++)
                {
                    for(int j = 0; j< m ; j++)
                    {
                        if(grid[i][j] == 1) return -1;
                    }
                }
             
             return distance;
         }

    
    
};