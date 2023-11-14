// Problem Link: https://leetcode.com/problems/bus-routes/

// INTUITION: Here we are given an array routes which contains bus routes where routes[i] is a bus routes
// that the ith bus repeats forever.
// For example, if routes[0] = [1, 5, 7], this means that the 0th bus travels in the 
// sequence 1 -> 5 -> 7 -> 1 -> 5 -> 7 -> 1 -> ... forever.

// We are given a source and target where we have to reach.
// Input: routes = [[7,12],[4,5,15],[6],[15,19],[9,12,13]], source = 15, target = 12
// Output: -1 , means not possible to reach the target.

// The approach that comes to our mind is to first connect adjaceny list as mentioned, like connecting the stops.
// but while doing a dfs or bfs we can think of storing the route of current node and checking it with the route of 
// next node on our dfs or bfs, but the thing is that a bus stop can be present at multiple routes.

// But we will store the number of routes that a bus stop visits and store it in corresponding to every bus stop.

// By doing this we will come to know about all differnt routes that have same stop can be covered with one bus.
// We can see in the adjaceny list, what all routes are visited, and make sure of not visiting those routes again.
// From that routes i can map the stops from the routes array, and then check whether that stop is present on a new route or
// the existing visited route.
class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
          int n = routes.size();
            
            if(source == target) return 0;
          unordered_map<int, vector<int>> adj; // node, route_indices

          for(int i=0 ; i < n; i++)
          {
              for(int j =0 ; j < routes[i].size() ; j++)
              {
                  adj[routes[i][j]].push_back(i);
              }
          }

          queue<int> q;
          unordered_set<int> visited;
          for(int &elem : adj[source])
          {
              q.push(elem);
              visited.insert(elem);
          }
          int dist =0 ;
         
          while(!q.empty())
          {
              int sz = q.size();
              dist++;
              for(int i= 0 ; i < sz ; i++)
              {
                  int route_index = q.front();
                  q.pop();

                  for(int &stop: routes[route_index])
                  {
                      if(stop == target) return dist;

                      for(int &nextRoute : adj[stop])
                      {
                          if(!visited.count(nextRoute))
                          {
                              q.push(nextRoute);
                              visited.insert(nextRoute);
                          }
                      }
                  }
              }
          }

          return -1;


    }
};