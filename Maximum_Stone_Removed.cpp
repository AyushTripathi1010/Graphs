// GFG LINK: https://practice.geeksforgeeks.org/problems/maximum-stone-removal-1662179442/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=maximum-stone-removal

// INTUITION : in this question we have to find the maximum number of stones we, can
// remove , for this we will consider every row to be a node and every col to be a node
// eg , for A 5X5 mareix indexing will be from 0-4. so in that way there a 4 row indexes
// and 4 column indexes so total 4+ 4 + 1  = 9 nodes will be there, that is maxRow+ maxCol+1.
// where maxRow = 4 , maxCol = 4.
// 

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
    int maxRemove(vector<vector<int>>& stones, int n) {
        
        int maxRow = 0; 
        int maxCol = 0;
        
        // Counting number of Rows and Columns that are possible
        for(it : stones)
        {
            maxRow = max(maxRow , it[0]);
            maxCol = max(maxCol , it[1]);
            
        }
        
        // creating the all the nodes.
        Disjoint ds(maxRow + maxCol + 1);
        for(auto it : stones)
        {
            int RowNode = it[0];
            int ColNode = it[1] + maxRow +1;
            
            ds.UnionBySize(RowNode , ColNode);
            
        }
        
        
        int cntOfDisconnectedComponents =0 ;
        
        // there can be some nodes which do not have any stones
        // so to avoid counting of that we will write ds.size[i] > 1.
        // because every stone has 2 nodes associated with it , ColNode
        // and RowNode.
        // and for those rows and cols which do not have any stone
        // will have size = 1, which don't have to count.
        for(int i = 0; i < maxRow+maxCol+1 ; i++)
        {
            if(ds.parent[i] == i && ds.size[i] > 1)
            cntOfDisconnectedComponents++;
            
        }
        
        return n - cntOfDisconnectedComponents;
        
    }
};
