// GFG LINK : https://practice.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=implementing-dijkstra-set-1-adjacency-matrix

class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Min heap created to store the shortest distance at top.
        priority_queue<pair<int,int> , vector<pair<int, int>> , greater<pair<int,int>>> pq;
        
        vector<int> distance(V , 1e9);
        
        pq.push({0 ,S}); // distance , node
        distance[S] = 0;
        
        while(!pq.empty())
        {
            int dist = pq.top().first;
            int node = pq.top().second;
            
            pq.pop();
            
            
            for(auto elem : adj[node])
            {
                int dest_node = elem[0];
                int wt = elem[1];
                
                
                if(distance[node] + wt < distance[dest_node])
                {
                    distance[dest_node] = distance[node]  + wt;
                    pq.push({distance[dest_node] , dest_node});
                }
            }
        }
        
        return distance;
    }
};
