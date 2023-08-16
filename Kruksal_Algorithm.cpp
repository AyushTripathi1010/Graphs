// GFG LINK : https://practice.geeksforgeeks.org/problems/minimum-spanning-tree/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=minimum-spanning-tree 


 //  INTUITION : so we are using kruksal algorithm, to find 
 // the miniumum  cost of mst, in this algo we first sort all the
 // edges according to weights and then one by one iterate over all
 // the edges and connect them to their ultimate parent using 
 // disjoint set.

class Disjoint{
     vector<int> parent , size;
     public:
     Disjoint(int n)
     {
         parent.resize(n+1);
         size.resize(n+1, 1);
         
         //   making every node parent of themeselves.
         for(int i= 0 ; i <= n ; i++) parent[i] = i;
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
             size[pv]+= size[pu];
         }
         else
         {
             parent[pv] = pu;
             size[pu]+=size[pv];
         }
     }
};
class Solution
{
	public:
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        int sum =0 ;
        Disjoint ds(V);
        vector<pair<int, pair<int,int>>> edges;
        
        for(int i =0 ; i < V ; i++)
        {
            for(auto elem : adj[i])
            {
                int node = i;
                int adjNode = elem[0];
                int wt = elem[1];
                
                edges.push_back({wt , {node , adjNode}});
                
            }
        }
        
         //  now sort all the edges in increasing order of edge weights.
        sort(begin(edges) , end(edges));
        
        for(auto vec : edges)
        {
            int wt = vec.first;
            int u = vec.second.first;
            int v = vec.second.second;
            
             if(ds.findUParent(u) != ds.findUParent(v))
             {
                 sum+=wt;
                 ds.UnionBySize(u,v);
             }
        }
        
        return sum;
    }
    
};









