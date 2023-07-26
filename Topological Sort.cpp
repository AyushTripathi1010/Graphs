class Solution
{
	public:
	//Function to return list containing vertices in Topological order.
// 	void dfs(int node,  int *vis  , vector<int> adj[] , stack<int> &st)
// 	{
// 	    vis[node] = 1;
	    
// 	    for(auto elem : adj[node])
// 	    {
// 	        if(!vis[elem])
// 	        {
// 	            dfs(elem , vis, adj, st);
// 	        }
// 	    }
// 	    st.push(node);
	    
// 	}

 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    
	   // vector<int> topo;
	   // stack<int> st;
	   // int vis[V] = {0};
	   // for(int i =0 ; i < V; i++)
	   // {
	   //     if(!vis[i])
	   //     {
	   //         dfs(i , vis, adj, st );
	   //     }
	   // }
	    
	   // while(!st.empty())
	   // {   
	   //     topo.push_back(st.top());
	   //     st.pop();
	   // }
	   
	     vector<int> topo;
	     vector<int> indeg(V , 0);
	     
	     for(int i =0 ; i < V; i++)
	     {
	         for(auto elem : adj[i])
	         {
	             indeg[elem]++;
	         }
	     }
	     queue<int> q;
	  
	   
	   for(int i =0 ; i < V ; i++)
	   {
	       if(indeg[i]== 0) q.push(i);
	   }
	     
	     while(!q.empty())
	     {
	         int node = q.front();
	         
	         q.pop();
	         topo.push_back(node);
	         
	         for(auto elem : adj[node])
	         {  
	             indeg[elem]--;
	             if(indeg[elem] == 0)
	             q.push(elem);
	             
	             
	         }
	     }
	    
	    return topo;
	}
};