// GFG LINK : https://practice.geeksforgeeks.org/problems/connecting-the-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=connecting-the-graph 


// INTUITION : TO connect all discconected graph the minimum 
// eges required will be n-1 edges for n disconnected components.
// so we will count extra edges which should be greater than equal to
// n-1 edges.

class Disjoint
{
    public: 
    vector<int> parent, size;
    
    Disjoint(int n)
    {
        parent.resize(n+1);
        size.resize(n+1 , 1);
        
        for(int i = 0; i <=n; i++) parent[i] = i;
        
    }
    
    int findUParent(int node)
    {
        if(node == parent[node])
        return node;
        
        return parent[node] = findUParent(parent[node]);
    }
    
    void UnionBySize(int u , int v)
    {
        int pu = findUParent(u);
        int pv = findUParent(v);
        
        if(pu == pv) return;
        
        if(size[pu] < size[pv])
        {
            parent[pu] = pv;
            size[pv]+=size[pu];
        }
        else
        {
            parent[pv] = pu;
            size[pu]+= size[pv];
        }
    }
};
class Solution {
  public:
    int Solve(int n, vector<vector<int>>& edge) {
        // code here
        Disjoint ds(n);
        int cntExtras =0 ;
        
        for(auto it : edge)
        {
            int u = it[0];
            int v = it[1];
            
            if(ds.findUParent(u)!= ds.findUParent(v))
            ds.UnionBySize(u,v);
            else
            cntExtras++;  // means already connected, which means an
        				  //  extra edge.
            
        }
        
        //   now count the number of components
        int cntC =0;
        for(int i = 0; i< n ; i++)
        {
            if(ds.parent[i] == i) cntC++;
        }
        
        int ans = cntC-1; // the minimum edges required to connect all the connections
        
        // this means we have sufficent amount of extra edges.
        if(cntExtras >= ans) return ans;
        return -1;
        
    }
};