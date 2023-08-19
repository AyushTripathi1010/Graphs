// LEETCODE LINK : https://leetcode.com/problems/critical-connections-in-a-network/description/ 


// here we use the concept of time of insertion in dfs tin[] and
// low[] = minimum lowest time insertion of all adjacent nodes
// apart from parent.

// while doing the dfs we will mark tin[] and low[] with timer
// starting from 1 second. 
// we will always try to get the minimum lowest time of node
// by comparing it with lowest time of all other nodes.

// While backtracking we will compare the time of insertion
// of current node i.e to dfs call is goiing back to and the 
// the adjacent node from where it is going back.
// if the time of insertion of current node is smaller
// than the lowest time of insertion of adjacent node then that means
// there is a bridge.

class Solution {
public:

    void dfs(int node , int parent, vector<int> &vis , vector<int> adj[], vector<int> &tin , 
    vector<int> &low , int &timer , vector<vector<int>> &bridges)
    {
         
         tin[node] = timer;
         low[node] = timer;
         timer++;
         vis[node] = 1;

         for(auto elem : adj[node])
         {    
             if(elem == parent) continue;
             if(!vis[elem])
             {
                dfs(elem ,node,  vis , adj , tin , low , timer, bridges);
                
                low[node] = min(low[node] , low[elem]);

                // now check if this edge can be a bridge

                if(tin[node] < low[elem])
                {
                    bridges.push_back({node , elem});
                }


             }
             else
             {
                low[node] = min(low[node] , low[elem]);
             }
         }
         

    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {

          
          vector<int> tin(n) , low(n);
          vector<int> vis(n , 0);
          int timer = 1;
          
          vector<int> adj[n];

          for(auto it : connections)
          {
             adj[it[0]].push_back(it[1]);
             adj[it[1]].push_back(it[0]);

          }

          vector<vector<int>> bridges;

          for(int i =0 ; i < n ; i++)
          {
              if(!vis[i])
              {
                  dfs(i , -1,  vis , adj , tin , low , timer , bridges);
              }
          }

          return bridges;

        
    }
};