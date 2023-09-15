// Problem Link: https://leetcode.com/problems/min-cost-to-connect-all-points/ 

// INTUITION : here we have to just connect all the coorinates, and
// then create a mst , in this approach i have created mst using
// prims algorithm.
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        // using prims algorithm
    int n = points.size();
    priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> pq;

    unordered_map<int, vector<pair<int,int>>> adj;

    for(int i= 0 ; i < n ; i++)
    {
        for(int j = i+1 ; j < n ; j++)
        {
            int x_i = points[i][0];
            int y_i = points[i][1];

            int x_j = points[j][0];
            int y_j = points[j][1];

            int distance = abs(x_i - x_j)+ abs(y_i - y_j);

            adj[i].push_back({j , distance});
            adj[j].push_back({i , distance});

        }
    }
    vector<int> visited(n , 0);
    pq.push({0 , 0}); // wt, distance

    int cost= 0 ;
    while(!pq.empty())
    {
        int node = pq.top().second;
        int wt = pq.top().first;
        pq.pop();

        if(visited[node] == 1) continue;
        visited[node] = 1;

        cost+=wt;

        for(auto &elem : adj[node])
        {
            int adjnode = elem.first;
            int adjwt = elem.second;

            if(!visited[adjnode])
            pq.push({adjwt , adjnode});
        }




    }
    return cost;


    }
};