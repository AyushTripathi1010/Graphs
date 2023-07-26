class Solution {
  
    // Function to return a list containing the DFS traversal of the graph.
     void dfs(int node, vector<int> &vis, vector<int> adj[], vector<int> &storeDfs) {
         if(vis[node]) return;
        storeDfs.push_back(node); 
        vis[node] = 1; 
        for(auto elem : adj[node]) {
            
                 dfs(elem, vis, adj, storeDfs); 
            
        }
        //  for(int i =0 ; i<adj[node].size() ; i++){
        //      if(!vis[adj[node][i]])
        //      dfs(adj[node][i] , vis , adj , storeDfs);
        //  }
        
    }
    public:
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
              vector<int> storeDfs; 
	    vector<int> vis(V, 0); 
      for(int i = 0;i<V;i++) {
        if(!vis[i]) 
        dfs(i, vis, adj, storeDfs); 
      }
	    return storeDfs; 
        
    }
};