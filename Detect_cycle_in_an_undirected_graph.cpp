class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    
    bool bfs(int node , vector<bool> &visited , vector<int> adj[])
    {
        visited[node]= true;
        
        queue<pair<int,int>> q;
        q.push({node , -1}); // 0,-1
        
        while(!q.empty())
        {
            int curr = q.front().first;     // 1
            int parent = q.front().second; // 0
            
            q.pop();
            for(auto elem : adj[curr])        // 1-> 2 , 4
            {
                
                if(!visited[elem])
                {
                    visited[elem] = true;
                    q.push({elem , curr});   
                }
                else
                {
                    if(parent != elem)
                    return true;
                }
            }
        }
        
        return false;
    }
    
    
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        
        vector<bool> visited(V,false);
        
        for(int i =0 ; i<V ; i++)
        {
            if(!visited[i])
            {
                
                if(dfs(i, visited , adj ,-1)) return true;
            }
            
        }
        return false;
    }
};