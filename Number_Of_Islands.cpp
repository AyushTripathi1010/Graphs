// GFG LINK : https://practice.geeksforgeeks.org/problems/number-of-islands/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=number-of-islands

// INTUITION : here acccording to the given queries we have to count 
// the number of islands and also we have to check the 4 adjacent directions
// because if a new node is able to make an island with its adjacent nodes, then 
// it is not a new island and in that case we just union it with its adjacent node
// we only count if it  is a new node and has do not have adjacent island to it.

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
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        // code here
        
        Disjoint ds(n*m+1);
        int cnt =0; 
        vector<int> ans;
        int delrow[] = {0, 1 , 0 , -1};
        int delcol[] = {1 , 0 , -1 , 0};
        vector<vector<int>> vis(n , vector<int> (m , 0));
        for(auto it : operators)
        {
            int row = it[0];
            int col = it[1];
        
            int node = row*m + col; // only used for union purpose.
            
            // if a query gets repeated, we have to add this condition, so that
            // we don't again count the same island as a new island.
            if(vis[row][col] == 1)
            {
                ans.push_back(cnt);
                continue;
            }
            
            cnt++;  // initially we are considering it as a new island, 
            // while cheking the elements in all 4 directions, we will
            // come to know whether it's a  new island or not.
            vis[row][col] = 1;
            
            for(int i =0 ; i < 4 ; i++)
            {
                int nrow = delrow[i] + row;
                int ncol = delcol[i] + col;
                
                int adjNode = nrow*m + ncol;
                
                if(nrow>=0 && nrow< n && ncol >=0 && ncol < m && vis[nrow][ncol] == 1)
                {
                    if(ds.findUParent(adjNode) != ds.findUParent(node))
                    {
                        cnt--; // since this can be joined with the previous island
                        // so our assumption of considering it as a new island 
                        // is wrong so we will decrement the island count.
                        ds.UnionBySize(node, adjNode);
                    }
                }
                
                
            }
            // pushing our final count for every query.
            ans.push_back(cnt);
            
        }
        
        return ans;
    }
};