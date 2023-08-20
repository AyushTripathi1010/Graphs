// LEETCODE LINK : https://leetcode.com/problems/network-delay-time/description/ 


// INTUITION : here we have to find the time to reach the node
// which takes the maximum time to reach from the source node.
// but that time should be minimum possible.
// SO this question will be solve using dijkstra algo.
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
          
          priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> pq;

          vector<int> distance(n+1 , 1e9);

          vector<pair<int,int>> adj[n+1];

          for(auto vec : times)
          {
              adj[vec[0]].push_back({vec[1] , vec[2]});
          }

          pq.push({0 , k}); // dist , node

          distance[k] = 0;

          while(!pq.empty())
          {
              int timer = pq.top().first;
              int node = pq.top().second;
              pq.pop();

              for(auto elem : adj[node])
              {
                  int adjNode = elem.first;
                  int adjWt = elem.second;

                  if(timer + adjWt < distance[adjNode])
                  {
                      distance[adjNode] = timer + adjWt;
                      pq.push({distance[adjNode] , adjNode});
                  }
              }
          }
           int ans= 0 ;
           for(int i = 1 ; i<=n ; i++)
           {
               ans = max(ans , distance[i]);
           }

           return ans == 1e9 ? -1 : ans;
    }
};