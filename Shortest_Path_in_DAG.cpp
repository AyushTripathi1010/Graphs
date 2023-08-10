// GFG Link: https://practice.geeksforgeeks.org/problems/shortest-path-in-undirected-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=direct-acyclic-graph

 // INTUITION : DAG is Directed Acyclic Graph which has no cycles 
 //  in the question, we have to find the shotrtest distance to reach each node 
// now, comes the important point, that is , if i want the shortest distance, 
// to reach a particular node, that means i will have to start from its, 
// preceding nodes, so for each node i should know what is it's preceding node
// so to acheive that we are doing a topo sort, so that for 
// a prticular node, we can get the shortest distance, considering all it's
//  preceding nodes.


class Solution {
  public:
     void dfs(int node, stack<int> &st , vector<int>&vis, vector<pair<int,int>> adj[])
     {
         vis[node] = 1;
         
         for(auto elem : adj[node])
         {   
             int curr = elem.first;
             if(!vis[curr])
             {
                 dfs(curr, st, vis , adj);
             }
         }
         
         st.push(node);
     }
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        // code here
        
          vector<pair<int,int>> adj[N];
          
          for(auto vec:  edges)
          {
              adj[vec[0]].push_back({vec[1] , vec[2]});
          }
          
          stack<int> st;
          vector<int> vis(N , 0);
          
          for(int i= 0 ; i < N ; i++)
          {
              if(!vis[i])
              dfs(i , st , vis, adj);
          }
          
        //    create a distance vector to store shortest paths
        
            vector<int> distance(N , 1e9);
            distance[0] = 0;
            while(!st.empty())
            {
                int node = st.top();
                st.pop();
                
                //  relaxation of edges
                
                for(auto it : adj[node])
                {
                    int destination_node = it.first;
                    int wt = it.second;
                    
                    if(distance[node] + wt < distance[destination_node])
                    {
                        distance[destination_node] = distance[node]+ wt;
                    }
                    
                }
            }
            
            for(int i =0 ; i < N ; i++)
            {
                if(distance[i] == 1e9)  distance[i] = -1;
            }
            
            return distance;
    }
};