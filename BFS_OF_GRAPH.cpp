class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    
    void bfs(int source_node , vector<int> &visited , vector<int> adj[] , vector<int> &storeBfs)
    {
        
        visited[source_node]  = 1;
        
        queue<int> q;
        q.push(source_node);
        while(!q.empty())
        {
            int node = q.front();
                 q.pop();
                 storeBfs.push_back(node);
            for(auto elem : adj[node])
            {    
                if(!visited[elem])
                {
                    visited[elem] = 1;
                    q.push(elem);
                }
            }
        }
    }
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        
        vector<int> visited(V,0);
        vector<int> storeBfs;
        
        bfs(0, visited , adj , storeBfs );
        
        return storeBfs;
    }
};