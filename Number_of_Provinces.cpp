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
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        
        Disjoint ds(V+1);
        int cnt =0 ;
        for(int i = 0; i < V ; i++)
        {
            for(int j = 0 ;j< V ; j++)
            {
                if(adj[i][j] == 1)
                {
                    ds.UnionBySize(i , j);
                }
            }
        }
        
        for(int i =0 ;i < V ; i++)
        {
            if(ds.parent[i] == i ) cnt++;
        }
        
        return cnt;
    }
};
