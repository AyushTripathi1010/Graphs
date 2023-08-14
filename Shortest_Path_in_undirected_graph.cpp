 // GFG LINK: https://practice.geeksforgeeks.org/problems/shortest-path-in-weighted-undirected-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=shortest-path-in-weighted-undirected-graph

class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
       
    //   INTUITION : SO here the questions asks to print the shortest
    //  path between node 1 and node n , and each edge has some edge weight
    
    //  In order to print the shortest path we have used a parent array
    //  where initially each node is the parent of itself.
    
    //  The idea of parent array is to store which preceding adjacent 
    //  node is giving it the least distance .
    
    //  eg: To reach node 4,supoose  we had 3 precedence nodes as 1, 4,6
    //  which can lead to node 4 but out of these 3 nodes, the 
    //  smallest distance to reach node can be acheived via node
    // 6, therefore , the parent[4] = 6;
        
        priority_queue<pair<int,int> , vector<pair<int,int> >, greater<pair<int,int>>> pq;
        
        vector<int> distance(n+1 , 1e9);
        vector<int> parent(n+1);
        for(int i=  0 ; i<= n ; i++)
        {
            parent[i] = i;
        }
        vector<pair<int,int> > adj[n+1];
        
        for(auto vec : edges)
        {
            adj[vec[0]].push_back({vec[1] , vec[2]});
            adj[vec[1]].push_back({vec[0] , vec[2]});
            
        }
        
        pq.push({0 , 1}); // dist , node
        distance[1] = 0;
        while(!pq.empty())
        {
            int node = pq.top().second;
            int dist = pq.top().first;
            pq.pop();
            
            for(auto elem : adj[node])
            {
                int adjNode = elem.first;
                int wt = elem.second;
                
                if(distance[node] + wt < distance[adjNode])
                {
                    distance[adjNode] = distance[node] + wt;
                    pq.push({distance[adjNode] , adjNode});
                    parent[adjNode] = node;
                }
            }
        }
        
        // edge case if any node has a distance as 1e9 then return -1.
        if(distance[n] == 1e9) return {-1};
        vector<int> ans;
        
        // So we have initalise node = n, because it is our target node
        //  to reach , and our task is to reach node 1.
        
        // in the while condition parent[node] != node mean that 
        //  we still have a parent node for current node , till then
        // run the loop, as soon as it reaches node 1, 
        // parent[1]= 1, because it is starting node, so we
        //  will have to push it manually.
        
        int node = n;
        while(parent[node] != node)
        {
            ans.push_back(node);
            node = parent[node];
        }
        
        ans.push_back(1);
        
        reverse(begin(ans) , end(ans));
        
        return ans;
        
    }
};