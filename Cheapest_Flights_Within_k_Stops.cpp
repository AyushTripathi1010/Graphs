// GFG LINK : https://practice.geeksforgeeks.org/problems/cheapest-flights-within-k-stops/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=cheapest-flights-within-k-stops

//  INTUITION: Here we have to find the cheapest price from src to destination, but here the
//  the catch is that the path should satisfy 2 conditions, the price should be cheap,
//  and stops should be within k stops.

//  Eg: we have path which is giving us the cheapest price as compared to all other paths
//  but exceeds the k stops limit, then we will not consider this path.

//  So we have to apply the same dijkstra algorithm, and one extra condition, for
//  checking whether the stops are within k stops.


class Solution {
  public:
    int CheapestFLight(int n, vector<vector<int>>& flights, int src, int dst, int K)  {
        // Code here
        typedef pair<int, pair<int,int>> P;
        
        vector<pair<int,int>> adj[n];
        
        for(auto vec : flights)
        {
            adj[vec[0]].push_back({vec[1] , vec[2]});
        }
        
        
        queue<P> q;
        
        q.push({0, {src , 0}}); // stops ,  node , cost
        
        vector<int> distance(n , 1e9);
        distance[src] = 0;
        
        while(!q.empty())
        {
            int stops = q.front().first;
            int node = q.front().second.first;
            int cost = q.front().second.second;
            
            q.pop();
            // if(stops > K) continue; 
            for(auto elem : adj[node])
            {
                int adjNode = elem.first;
                int adjCost = elem.second;

                //  eg : 1 -> 2 -> 3 -> 4 -> 5    , k = 3
                //  so at node  = 1 , k = 0
                //  at node  = 2 , k = 1
                //  at node  = 3 , k = 2
                //  at node = 4 , k = 3 , at this point also we can move ahead 
                //  due to our stops <= k condition and reach destination.
                if(stops <= K && cost + adjCost < distance[adjNode])
                {
                    distance[adjNode] = cost + adjCost; 
                    q.push({stops+1 , {adjNode, distance[adjNode]}});
                }
            }
            
        
        }
        
        if(distance[dst] == 1e9) return -1;
        
        return distance[dst];
    }
};