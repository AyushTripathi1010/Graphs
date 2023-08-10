// GFG Link: https://practice.geeksforgeeks.org/problems/shortest-path-in-undirected-graph-having-unit-distance/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=shortest-path-in-undirected-graph-having-unit-distance 
class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        // code here
         
         vector<int> adj[N];
         vector<int> vis(N , 0);
         for(auto vec: edges)
         {
             adj[vec[0]].push_back(vec[1]);
             adj[vec[1]].push_back(vec[0]);
         }
        queue<pair<int,int> > q;
         
        q.push({src , 0});
        vis[src] = 1;
        vector<int> distance(N, -1);
        
        while(!q.empty())
        {
            int node = q.front().first;
            int wt = q.front().second;
            distance[node] = wt;
            
            q.pop();
            
            for(auto elem : adj[node])
            {   
                if(!vis[elem])
                {q.push({elem , wt+1});
                 vis[elem] = 1;
                }
            }
            
            
        }
        
        return distance;
    }
};