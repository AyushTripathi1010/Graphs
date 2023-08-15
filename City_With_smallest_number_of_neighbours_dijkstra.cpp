// GFG LINK : https://practice.geeksforgeeks.org/problems/city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=city-with-the-smallest-number-of-neighbors-at-a-threshold-distance


//  INTUITION : We have solve this question using multi source
//  dijkstra where , we have considered every node as starting
// node once and considering that particular node as starting node 
// calculated the distance array.

//  We have created a 2D distance array and for every node
// we will maintain the shortest distance in the corressponding
// row of that node.

class Solution {
  public:
    vector<int> dijkstra(vector<pair<int,int>> adj[] , int n , int src)
    {
        priority_queue<pair<int,int> , vector<pair<int,int>>, greater<pair<int,int>>> pq;
        
        pq.push({0 , src});  // dist, node
        vector<int> distance(n , 1e9);
        distance[src] = 0;
        
        while(!pq.empty())
        {
            int node = pq.top().second;
            int dist = pq.top().first;
            pq.pop();
            
            for(auto elem : adj[node])
            {
                int adjNode = elem.first;
                int wt = elem.second;
                
                if(dist + wt < distance[adjNode])
                {
                    distance[adjNode] = dist + wt;
                    pq.push({distance[adjNode] , adjNode});
                }
            }
        }
        
        return distance;
        
    }
    int findCity(int n, int m, vector<vector<int>>& edges, int distanceThreshold)
    {
        
        vector<pair<int,int> > adj[n];
        
        // Created the adjacency list for dijkstra.
        for( auto vec : edges)
        {
            adj[vec[0]].push_back({vec[1] , vec[2]});
            adj[vec[1]].push_back({vec[0] , vec[2]});
        }
        
        vector<vector<int>> distance(n , vector<int> (n , 1e9));
        
        for(int i = 0 ; i< n ;i++)
        {
            distance[i] = dijkstra(adj , n, i);
        }
        
        int cityno = -1;
        int citymax = n;
        for(int i = 0; i< n; i++)
        {  int cnt =0 ;
            for(int j =0 ; j < n; j++)
            {  
                if(distance[i][j] <= distanceThreshold)
                {
                    cnt++;
                }
            }
            
            if(cnt <= citymax)
            {
                citymax = cnt;
                cityno = i;
            }
            
        }
        
        return cityno;
        
    }
};