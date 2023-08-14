// GFG LINK : https://practice.geeksforgeeks.org/problems/shortest-path-in-a-binary-maze-1655453161/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=shortest-path-in-a-binary-maze

class Solution {
  public:
  
  int bfs(int r,int c ,vector<vector<bool>> &visited ,pair<int,int> src ,pair<int,int>des, vector<vector<int>> grid,int &distance )
  {
      
         queue<pair<pair<int,int>, int>> q;
         
         q.push({src , 0});
         visited[src.first][src.second] = true;
         
         while(!q.empty())
         {
             int row = q.front().first.first;
             int col = q.front().first.second;
             int dist = q.front().second;
             
             if(row == des.first && col== des.second) return dist;
             
             q.pop();
             
             for(int dj1 = -1 ; dj1<=1; dj1++)
             {
                 for(int dj2 =-1 ; dj2<=1 ; dj2++)
                 {
                     if(abs(dj1) == abs(dj2)) continue;
                     
                     int nrow = row+dj1;
                     int ncol = col+dj2;
                     
                     if(nrow>=0 && nrow<r && ncol>=0 && ncol<c && !visited[nrow][ncol] && grid[nrow][ncol] == 1)
                     {
                         visited[nrow][ncol] = true;
                         q.push({{nrow,ncol} , dist+1});
                     }
                 }
             }
         }
         return -1;
         
  }
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
                         
                         
                         int r = grid.size();
                         int c = grid[0].size();
                         
                          vector<vector<bool>> visited(r , vector<bool> (c,false));
                          int distance = 1e4;
                           return bfs(r,c, visited , source , destination , grid , distance);
                           
                          
        // code here
    }
};