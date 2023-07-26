class Solution {
public:
    // bool dfs(int node , vector<int> adj[] , vector<int> &colored, int color)
    // {
    //     colored[node] = color;
    //     for(auto elem: adj[node])
    //     {   
    //         if(colored[elem] == 2)
    //         { 
    //           if(!dfs(elem , adj ,colored , !color )) return false;
    //         }
    //         else
    //         {
    //             if(colored[elem] == colored[node]) return false;
    //         }
    //     }
        
    //     return true;
    // }
    
    bool bfs(int node, vector<int> adj[] , vector<int> &colored, int color)
    {
        queue<pair<int,int> > q;  // node, color
        
        q.push({node, color});
        
        while(!q.empty())
        {
            int curr = q.front().first;
            int col = q.front().second;
            colored[curr] = col;
            q.pop();
            
            for(auto elem : adj[curr])
            {
                if(colored[elem] == 2)
                {
                    q.push({elem , !col});
                }
                else
                {
                    if(colored[elem] == col) return false;
                }
            }
            
          
            
        }
          return true;
    }
	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    
	    vector<int> colored(V , 2);
	    
	    for(int i = 0; i < V ; i++)
	    {
	        if(colored[i] == 2)
	        {
	            if(!bfs( i, adj , colored, 0)) return false;
	        }
	    }
	    
	    
	    return true;
	    
	    
	    
	    
	    
	    
	    
	    
	    
	}

};