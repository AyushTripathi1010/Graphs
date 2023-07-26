class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    // 4-2-1
    //   |
    //   3
    bool dfs(int node, vector<int> &vis , vector<int> adj[], int parent)
    {
        vis[node] = 1;
        
        for(auto elem : adj[node])
        {
            if(!vis[elem])
            {
                if(dfs(elem , vis , adj, node)) return true;
            }
            else 
            {
                if(elem != parent) return true;   
                
            }
          
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        
        vector<int> vis(V, 0);
        
        for(int i =0 ; i<V; i++)
        {
            if(!vis[i])
            {
                if(dfs(i , vis , adj, -1)) return true;
            }
        }
        
        return false;
    }
};