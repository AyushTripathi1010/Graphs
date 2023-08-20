// GFG LINK: https://practice.geeksforgeeks.org/problems/detect-cycle-using-dsu/1


// INTUITION : here we have to detext cycle in dsu using dsu
// so if an edge between u and v forms a cycle then ultimate
// parent of both u and v will be equal.
// but since it is a directed graph so if there is an edge
//  between 1 and 0 then there is a cycle between 0 and 1.
//  and while iterating the adjacency list suppose we did union
// operation for 0 to 1 edge, then in future we will also come
// accross 1 to 0 edge in adjacency list but this time ultimate
// parent of both nodes will be same so according to our logic
// the result will, there is a cycle, which is wrong,
// we have to check for an edge only once so to avoid checks
// on same edge again, we will write the condition of ( u < v)
// so that edge is checked only once.

class Disjoint{
    
    public: 
    vector<int> parent, size;
    
    Disjoint(int n)
    {
        size.resize(n+1, 1);
        parent.resize(n+1);
        
        for(int i =0 ; i <=n ; i++)
        parent[i] = i;
    }
    
    int findUParent(int node)
    {
        if(node == parent[node]) return node;
        
        return parent[node] = findUParent(parent[node]);
    }
    
    void UnionBySize(int u , int v)
    {
        int pu = findUParent(u);
        int pv = findUParent(v);
        
        if(pu == pv) return ;
        
        if(size[pu] > size[pv])
        {
            size[pu]+= size[pv];
            parent[pv] = pu;
        }
        else
        {
            size[pv]+= size[pu];
            parent[pu] = pv;
        }
    }
};


class Solution
{
    public:
    //Function to detect cycle using DSU in an undirected graph.
	int detectCycle(int V, vector<int>adj[])
	{
	    
	     Disjoint ds(V);
	     
	     for(int u= 0 ; u < V ; u++)
	     {
	         for(auto v : adj[u])
	         { 
	             if(u < v )
	             {
	                 if(ds.findUParent(u) == ds.findUParent(v))
	                 {
	                     return 1;
	                 }
	                 
	                 ds.UnionBySize(u , v);
	             }
	         }
	     }
	     return 0;
	}
	
	
};
