class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    // Code here
	    
	    int n = grid.size();
	     int m = grid[0].size();
	     vector<vector<int>> ans = grid;
	     
	     queue<pair<pair<int,int>, int>> q; // row , col , distance
	     for(int i= 0 ; i < n ; i++)
	     {
	         for(int j=  0 ; j<m ; j++)
	         {
	             if(grid[i][j] == 1)
	             {
	                 q.push({{i, j}, 0});
	             }
	         }
	         
	     }
	     
	     int delrow[] = {0, 1, 0, -1};
         int delcol[] = {1, 0, -1, 0};
	     
	     while(!q.empty())
	     {
	         int row = q.front().first.first;
	         int col = q.front().first.second;
	         int dist = q.front().second;
	         q.pop();
	         
	         ans[row][col] = dist;
	    for(int i = 0; i<4 ; i++)
                 {
                     int nrow = row + delrow[i];
                     int ncol = col + delcol[i];
                         
                     if(nrow >=0 && nrow < n && ncol>=0 && ncol<m && grid[nrow][ncol] == 0)
                        {
                             q.push({{nrow,ncol}, dist+1});
                             grid[nrow][ncol] = 2;
                        }
                 }
	     }
	     
	     return ans;
	}
};