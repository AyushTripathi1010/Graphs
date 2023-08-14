// GFG LINK : https://practice.geeksforgeeks.org/problems/path-with-minimum-effort/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=path-with-minimum-effort


//  INTUITION: here in question we have to start from top-left corner
//  and reach bottom right corner, and also we need the minimum effort
//  which is bascially the height difference betwee adjacent nodes.

//  suppose you are moving on a path and till now, you have 
//  the maximum absolute difference of 5 , but now on reaching to next
// node the absolute height difference between next node and current
//  node is 2 , but we will update the distance of next node to 
//  5 and not 2, since on a path we have to maintain that maximum absolute
//  difference, untill we reach destination.

//  but also it does not mean that if i reach destination with distance
//  of 5 , then it is my final answer , we will have to look other possiblities
// also suppose from some other path i reach the destination node
//  with distance of 3, then i will update the destination with 
//  3, according to dijkstra algo, 

// So the main thing is we have to maintain a maximum effort ,on a path
// and out of all the different maximum efforts of different path
// we will consider the minimum effort, which will be acheived by dijkstra algo.



class Solution {
  public:
    int MinimumEffort(vector<vector<int>>& heights) {
        // Code here
        int n = heights.size();
        int m = heights[0].size();
        typedef pair<int, pair<int,int>>  P;
        priority_queue< P , vector<P> , greater<P>> pq;
        
         vector<vector<int>> distance(n , vector<int> (m , 1e9));
        pq.push({0 , {0 , 0}});
        distance[0][0]  = 0;
        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0 , 1, 0, -1};
       
        
        while(!pq.empty())
        {
            int diff = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            pq.pop();
            if(row == n-1 && col == m-1) return diff;
            for(int i = 0; i < 4 ; i++)
            {
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];
                
                if(nrow >=0 && nrow < n && ncol >= 0 && ncol<m)
                {
                    int newEffort = max(abs(heights[row][col] - heights[nrow][ncol]) , diff);
                    if( newEffort < distance[nrow][ncol] )
                    {
                        distance[nrow][ncol] = newEffort;
                        pq.push({distance[nrow][ncol] , {nrow, ncol}});
                    }
                }
            }
            
            
        }
        return 0;
    }
};
