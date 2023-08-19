// LeetCode LINK: https://leetcode.com/problems/find-critical-and-pseudo-critical-edges-in-minimum-spanning-tree/description/ 


// INTUITION : critical edges are those on whose edge removal
// mst weight increases by adding some other edge.

// psideo critical edges are those whose presence or absence
// in MST does not affect MST weight.

// Here we are first finding the ideal weight of MST by kruksal
// algo and then skipping every edge once for checking critical
// edge and adding the edge for psuedo critical connection .

// Note: For every kruksal call a new dsu is created from starting.
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

int N;
class Solution {
public:
    int kruksal(vector<vector<int>> &edges , int skip_edge , int add_edge)
    {    
         
         Disjoint ds(N);
         int sum = 0;
         int edge_cnt =0 ;

        // We are writing the add edge condition here because it
        // may happen that the edge that we want to add may not be 
        // accepted by kruskal algo to find mst, but we still want to  
        // take it.
        // and check whether by taking it , we get mst or not.
        if(add_edge != -1) 
        {
            ds.UnionBySize(edges[add_edge][0] , edges[add_edge][1] );
            sum+= edges[add_edge][2];
            edge_cnt++;
        }
         
         
         
        for(int i =0 ; i<  edges.size(); i++)
        {    
            if(skip_edge == i)
            {
                continue;
            }
            int wt = edges[i][2];
            int u = edges[i][0];
            int v = edges[i][1];
            
             if(ds.findUParent(u) != ds.findUParent(v))
             {
                 sum+=wt;
                 ds.UnionBySize(u,v);
                 edge_cnt++;
             }
        }
        //  edge case if by skipping or adding we are not able
        //  to make mst then not possible.
        if(edge_cnt != N-1) return INT_MAX;

        return sum;
    
    }
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
         
           N  =n;
        //    since we are going to solve it using kruksal, we will have to 
        // first sort the edges , but also maintain the indexing so
        // we will also store the indexes in edges vector, and then sort
        

        for(int i = 0; i < edges.size() ; i++)
        {
            edges[i].push_back(i);
        }

        
        auto lamda  = [&](vector<int>& v1 , vector<int>& v2)
        {
            return v1[2] < v2[2];
        };

        sort(edges.begin() , edges.end() , lamda);

        // Now find the MST weight;

        int MST = kruksal(edges , -1 , -1);
          
          vector<int> critical , psuedo_critical;
        // check for critical edge and psuedo critical edge.

        for(int i =0 ; i < edges.size() ; i++)
        {
             
             if(kruksal(edges , i  , -1) > MST) // skip the ith edge
             critical.push_back(edges[i][3]);
             else if(kruksal(edges , -1 , i) == MST) // adding the ith edge
             psuedo_critical.push_back(edges[i][3]);
        }

        
        vector<vector<int> > ans;
        
        ans.push_back(critical);
        ans.push_back(psuedo_critical);

        return ans;

    }
};