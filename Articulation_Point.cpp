// GFG LINK : https://practice.geeksforgeeks.org/problems/articulation-point-1/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=articulation-point 


// INTUITION: same approach as bridges in graph, but here
// while comparing a node with it's adjacent node we will
// update the low[] of current node with the time of insertions
// of adjacent node by taking minimum of all time.
// rather than updating the low with  low's of all nodes.


class Solution {
  public:
  int timer = 1;
   void dfs(int node , int parent , vector<int>& vis , vector<int>& tin , vector<int>& low, vector<int> adj[] , vector<int>& mark)
   {
         vis[node] = 1;
         
         tin[node] = low[node] = timer;
         timer++;
         int child = 0;
         for(auto elem : adj[node])
         {
             if(elem == parent) continue;
             
             if(!vis[elem])
             {
                 dfs(elem , node, vis, tin , low , adj , mark);
                 
                 // only compare with low's while backtracking.
                 low[node] = min(low[node] , low[elem]);
                 
                 // don't compare with parent node
                 if(low[elem] >= tin[node] && parent != -1)
                 {
                     mark[node] = 1;
                 }
                 
                 // count the children of parent nodes, 

                 child++;
             }
             else
             {
                 low[node] = min(low[node] , tin[elem]);
             }
         }
           // if parent nodes has more than 1 children
           // then the parent node is also an articulation
           // point.
         if(child > 1 && parent == -1) mark[node] = 1;
   }
    vector<int> articulationPoints(int V, vector<int>adj[]) {
        // Code here
          
          vector<int> vis(V , 0);
          vector<int> tin(V , 0);
          vector<int> low(V , 0);
          vector<int> ans , mark(V,0);
          
          for(int i = 0; i < V ; i++)
          {
              if(!vis[i])
          dfs(i ,-1, vis , tin , low , adj, mark);
          }
          
          for(int i = 0 ; i < V ; i++)
          {
              if(mark[i] == 1)
              ans.push_back(i);
          }
          

          //  this means there is no articulation point.
          if(ans.size() == 0) return {-1};
          
          return ans;
          
    }
};