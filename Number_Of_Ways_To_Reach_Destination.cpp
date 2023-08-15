// GFG LINK : https://practice.geeksforgeeks.org/problems/number-of-ways-to-arrive-at-destination/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=/number-of-ways-to-arrive-at-destination 


// INTUITION : First thing we have to find the nuumber of ways to reach target node,
//  , but there is a point to notice that we can't directly
//  say that 3 is the answer if only 3 nodes are reaching the
//  target node, because there might be nodes which are reaching 
// the target node, via some other node.

// So Why are we using set ?
// Set is acting like a min heap to store the shortest distance,
// but also to avoid duplicate entries , eg: to reach node 5 with
//  distance 3, there can be multiple ways, so just store 1 occurence
// of it in the map.

// What is te use of way array ?
// SO for each node we will have to check what all nodes can reach
//  to a node, so this will be calculted for every node.

// If i get a smaller distance to reach a node, i will update
//  it's distance and update it ways to ways of precedence node
//  but if i get an equal distance to reach a node again, 
//  i will add those ways also.


class Solution {
  public:
    int countPaths(int n, vector<vector<int>>& roads) {
        // code here
        
        vector<pair<int,int>> adj[n];
        
         long long mod = 1e9+7;
        for(auto vec : roads)
        {
            adj[vec[0]].push_back({vec[1] , vec[2]});
            adj[vec[1]].push_back({vec[0],  vec[2]});
        }
        set<pair<long long,long long>> s;
        
        vector<long long> dist(n,1e15), ways(n , 0);
        
        dist[0] = 0;
        ways[0] = 1; // to reach the nstarting node itself, it takes 1 way. 
        
        s.insert({dist[0] , 0});
        
        while(!s.empty())
        {
            auto it = *(s.begin());
            int node = it.second;
            long long distance = it.first;
            
            s.erase(it);
            
            for(auto elem : adj[node])
            {
                int curr_node = elem.first;
                long long edgeW = elem.second;
                
                // if from other path also we get same distance , then add those ways also.
                if(distance +edgeW == dist[curr_node])
                {
                    ways[curr_node] = (ways[node] + ways[curr_node])%mod;
                }

                // this means got a new shorter distance
                // so update its ways to ways of precedence node
                if(distance + edgeW < dist[curr_node])
                {
                    if(dist[curr_node] != 1e15)
                    s.erase({dist[curr_node] , curr_node});
                    
                    dist[curr_node] = distance + edgeW;
                    ways[curr_node] = ways[node]%mod;
                    s.insert({dist[curr_node] , curr_node});
                    
                    
                    
                }
            }
            
        }
        
        
          return ways[n-1];
        
    }
};
