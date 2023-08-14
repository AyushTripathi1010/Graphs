// GFG LINK: https://practice.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=implementing-dijkstra-set-1-adjacency-matrix

class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        
        set<pair<int,int>> s;
        
        vector<int> distance(V , 1e9);
        
        s.insert({0 , S}); // dist , node
        distance[S] = 0;
        while(!s.empty())
        {
            auto it = *(s.begin());
            int node = it.second;
            int dist = it.first;
            
            s.erase({dist,node});
            for(auto elem : adj[node])
            {
                int adjNode = elem[0];
                int wt = elem[1];
                  
                 
                if(dist + wt < distance[adjNode])
                {
                    if(distance[adjNode] != 1e9)
                 {
                    s.erase({distance[adjNode] , adjNode});   
                 }
                    distance[adjNode] = dist + wt;
                    s.insert({distance[adjNode] , adjNode});
                }
                
            }
            
        }
        return distance;
        
        
    }
};