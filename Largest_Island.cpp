// GFG LINK : https://practice.geeksforgeeks.org/problems/maximum-connected-group/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=maximum-connected-group 

// INTUITION : First connect all islands and after that replace every 0 with 1 and 
// try to get the largest island possible, also use set to avoid addition of
// same island again.
// and remember the edge case of where all elements are 1.
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
    int MaxConnection(vector<vector<int>>& grid) {
           
          
           int n = grid.size();
           
           
            Disjoint ds(n*n);
            int delrow[] = {0, 1 , 0 , -1};
            int delcol[] = {1 , 0 , -1 , 0};
           
        //    Step-1: connect all the 1's in graph.
           for(int i =0 ; i < n ; i++)
           {
               for(int j =0 ; j < n ; j++)
               {
                   if(grid[i][j] == 0) continue;
                   
                   int row  = i;
                   int col = j;
                   
                   int node = row*n + col;
                   
                   for(int i =0 ; i < 4; i++)
                   {   
                       int nrow = delrow[i] + row;
                       int ncol = delcol[i] + col;
                       int adjNode = nrow*n + ncol;
                       
                       if(nrow>=0 && nrow< n && ncol >=0 && ncol < n)
                       {
                           if(grid[nrow][ncol] == 1)
                           {
                               ds.UnionBySize(node , adjNode);
                           }
                       }
                   }
               }
           }
           
           
        //   Step 2 : replace every 0 with one and try to get largest island
        // note for while replacing 0 and checking in all 4 directions for island
        // connectivity , it may happen that one island has covered a 0 node
        // in 2 adjacent directions, so we might end up counting the same island twice
        // so for that reason we will use set so that an island is counted inly once
        
        unordered_set<int> s;
        int ans =0;
        for(int i = 0 ; i <  n ; i++)
        {
            for(int j = 0; j  < n ; j++)
            {
                if(grid[i][j] == 1) continue;
                
                int row = i;
                int col = j;
                
                int node = row*n + col;
                
                int sz =0 ;
                for(int i = 0; i < 4 ; i++)
                {
                    int nrow = row + delrow[i];
                    int ncol = col + delcol[i];
                    
                    int adjNode = nrow*n + ncol;
                    
                    if(nrow>=0 && nrow< n && ncol >=0 && ncol < n)
                    {
                        if(grid[nrow][ncol] == 1)
                        {
                            int ultimate_node = ds.findUParent(adjNode);
                            
                            if(s.find(ultimate_node) == s.end())
                            sz+= ds.size[ultimate_node];
                            
                            s.insert(ultimate_node);
                            
                        }
                    }
                }
                s.clear();
                
                ans = max(ans , sz+1);
            }
        }
        
        // covering an edge case what if all elements of matrix is 1.
        // then ans would be 0 and expected ans would be n*n;
        // but we can't directly write n*n below, becuse in cases where 
        // all elements are not 1,  would have ans as expected answer not n*n.
        // so insted of writing n*n we have replaced it with ultimate parent
        //  of 0.
        return max(ans , ds.size[ds.findUParent(0)]);
        
    }
};
