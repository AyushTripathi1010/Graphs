// GFG LINK : https://practice.geeksforgeeks.org/problems/shortest-path-in-a-binary-maze-1655453161/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=shortest-path-in-a-binary-mazeclass Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
        
        //  Dijstra using queue as every node is at at a unit disatnce from each other
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, pair<int,int>> > q; // dist, row, col
        
        vector<vector<int>> distance(n , vector<int> (m , 1e9));
        
        //  Edge Case if source is equal to destination, 

        if(source.first==destination.first && source.second==destination.second) 
        return 0; 

        distance[source.first][source.second] = 0;
        
        q.push({0 , {source.first, source.second}});
        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0 , 1, 0, -1};
        while(!q.empty())
        {
            int dist = q.front().first;
            int row = q.front().second.first;
            int col = q.front().second.second;
            q.pop();
            
            //  if(row == destination.first && col == destination.second) return dist;
            
            for(int i = 0; i < 4 ; i++)
            {
                int nrow = row+ delrow[i];
                int ncol = col + delcol[i];
                
                if(nrow>=0 && nrow <n && ncol>=0 && ncol < m && grid[nrow][ncol] == 1)
                {
                    if(distance[row][col] + 1 < distance[nrow][ncol])
                    {
                        
                        distance[nrow][ncol] = distance[row][col] + 1;
                        if(nrow == destination.first && ncol == destination.second) return dist+1;
                        q.push({distance[nrow][ncol] , {nrow,ncol}});
                    }
                    
                }
            }
            
        }
        
        return -1;
        
    }
};
