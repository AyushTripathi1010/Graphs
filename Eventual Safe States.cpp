// GFG Link: https://practice.geeksforgeeks.org/problems/eventual-safe-states/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=eventual-safe-states

class Solution {
  public:
    bool dfs(int node, vector<int> &pathvis, vector<int> &vis , vector<int> adj[])
    {
        
        vis[node] = 1;
        pathvis[node] = 1;
        
        for(auto elem  : adj[node])
        {
            if(!vis[elem])
            {
                if(dfs(elem , pathvis, vis, adj))
                {
                    
                    return true;
                }
            }
            else if(vis[elem] && pathvis[elem])
            {   
                
                return true;
            }
            
            
        }
        pathvis[node] = 0;
        
        return false;
    }
    
    
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        // code here
        
        // DFS : For the dfs method after all the nodes are visited
        //  if any nodes has path visited = 0, means that node is 
        // a terminal node.
        vector<int> vis(V, 0);
        vector<int> pathvis(V, 0);
        
        vector<int> safeNodes;
        for(int i = 0; i < V; i++)
        {
            if(!vis[i])
            {
                dfs(i , pathvis, vis, adj);
                
            }
        }
        
        for(int i =0 ; i < V ; i++) 
        {
            if(pathvis[i] == 0) safeNodes.push_back(i);
        }
        return safeNodes;
        
        










        // BFS : in BFS method:
         

         // Step1: Is to reverse the edges of the graph, so that 
        // now the terminal nodes will have 0 indegree.
        // and we can start our dfs from the terminal nodes.
         vector<int> adjRev[V];
	     for(int i =0 ; i < V ; i++)
	     {
	         for(auto elem : adj[i])
	         {
	             adjRev[elem].push_back(i);
	         }
	     }

         //  Step2: Now the topo sort begins.
        vector<int> topo;
        
        vector<int> indeg(V ,0);
        
        for(int i = 0; i < V ; i++)
        {
            for(auto elem : adjRev[i])
            {
                indeg[elem]++;
            }
        }
        
        queue<int> q;
        
        for(int i = 0; i < V; i++)
        {
            if(indeg[i] == 0)  q.push(i);
        }
        
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            topo.push_back(node);
            for(auto elem : adjRev[node])
            {
                indeg[elem]--;
                if(indeg[elem] ==0) q.push(elem);
            }
        }
        
        sort(topo.begin() , topo.end());
        return topo;
    }
};