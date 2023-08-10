// GFG Link: https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=detect-cycle-in-a-directed-graph 

class Solution {
  public:
    // Function to detect cycle in a directed graph.
    
    // if a node is a part of cycle , then it will be both 
    // visited and path visited, but if it not a part of cycle
    //  then it can be either not visited , or node can be 
    // visited but not path visited.
    bool dfs(int node, vector<int> &pathvis, vector<int> &vis ,vector<int>adj[])
    {
        vis[node] =1 ;
        pathvis[node] =1;
        
        for(auto elem : adj[node])
        {
            if(!vis[elem])
            {
                if(dfs(elem , pathvis, vis, adj))
                {
                    return true;
                }
                
            }
            else
            {   

                if(vis[elem] && pathvis[elem]) return true;
            }
        }
        
        pathvis[node] = 0;
        
        return false;
    }
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        
        //  Here a concept of visited and path visited is used
        
        vector<int> vis(V, 0);
        vector<int> pathvis(V, 0);
        
        for(int i = 0; i < V; i++)
        {
            if(!vis[i])
            {
                if(dfs(i , pathvis, vis, adj))
                {
                    return true;
                }
            }
        }
        
        return false;
    }
};