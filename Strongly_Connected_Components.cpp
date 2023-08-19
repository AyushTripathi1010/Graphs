// GFG LINK : https://practice.geeksforgeeks.org/problems/strongly-connected-components-kosarajus-algo/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=strongly-connected-components-kosarajus-algo

//  Strongly Connected Components in a graph are those nodes which are 
// connected to every other node in the graph.
// In this question we have to find the count of strongly connected components.
// FOr which we are applying the KosaRaju algorithm.


// the reversing of graph doesn't affect the internal strongly connected components
// but does affect different external ssc's.
// because in normal dfs call we might end up in visiting all nodes, hence not know
// how many ssc's are actually there, but rerversing of graph avoid us to go 
// to a new scc.

// sorting of edges is important, so that at top of stack we always have the 
// node of 1st strongly connected component.

class Solution
{
	public:
	void dfs(int node,  vector<vector<int>>&adj , vector<int>&vis , stack<int> &st)
	{
	    vis[node] =1;
	    
	    for(auto elem : adj[node])
	    {
	        if(!vis[elem])
	        {
	            dfs(elem , adj , vis, st);
	        }
	    }
	    st.push(node);
	}
	
	
	void dfs2(int node,  vector<int> adj[] , vector<int>&vis)
	{
	    vis[node] =1;
	    
	    for(auto elem : adj[node])
	    {
	        if(!vis[elem])
	        {
	            dfs2(elem , adj , vis);
	        }
	    }
	}
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<vector<int>>&  adj)
    {
        
         
        //  Step 1 : Sort all the nodes according to finishing time, that is
        // a node can which is terminal will finish first and will be pushed in the
        // stack.
        // so idea is kind of topo sort.
        
        vector<int> vis(V , 0);
        stack<int> st;
        for(int i =0 ; i < V; i++)
        {
            if(!vis[i])
            dfs(i , adj, vis , st);
        }
        
        // Step 2 : reverse the edges, so make an adjaceny list which stores
        // the graph in reverse format, and also mark the visited nodes as unvisited.
        
        vector<int> adjR[V];
        for(int i = 0; i < V; i++)
        {    vis[i]= 0;
            for(auto elem : adj[i])
            {
                adjR[elem].push_back(i);
            }
        }
        
        // Now do the dfs again and count the number of ssc's, by popping every element
        // of stack, and this time dfs will be call on reversed graph adjaceny list.
          int scc = 0;
         while(!st.empty())
         {
             int node = st.top();
             st.pop();
             
             if(!vis[node])
             {
                 scc++;
               dfs2(node , adjR , vis);
             }
         }
         
         return scc;
        
        
    }
};