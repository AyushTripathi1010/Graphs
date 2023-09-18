// GFG LINK : https://practice.geeksforgeeks.org/problems/minimum-spanning-tree/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=minimum-spanning-tree 

class Solution
{
    // NOTE: The purpse of adding if(vis[node] == 1) continue; is that same node
    // can occur more than once in the priority queue, because we are marking a
    // node visited, only when it is getting popped out, so if we do not add
    // this statement, it will also take the weights of node that is visited
    // and will add it in the sum, because priority queue works until it gerts 
    // empty, so to avoid exta weight addtions we have put the continue statement
    // to avoid the addition.

    // eg : 1 - 2 - 3 - 4 - 5 - 1 , circular graph with 5 nodes and 5 edges
    //  just try to make the priority queue for this graph, all doubts will
    // be clear.

   //  In Prim's algorithm we can start making mst from any node, but we will have to track wt of previously unused
   //   node weights.

	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> pq;
        
        pq.push({0 , 0}); //  dist ,node
        
        vector<int> vis(V , 0);
        int sum = 0;
        while(!pq.empty())
        {
            int cost = pq.top().first;
            int node = pq.top().second;
            pq.pop();
        
            if(vis[node] == 1) continue;
            vis[node]  = 1;
            sum+=cost;
            
            for(auto elem : adj[node])
            {
                int adjNode = elem[0];
                int wt = elem[1];
                
                if(!vis[adjNode])
                {
                    pq.push({wt , adjNode});
                }
                
            }
        }
        
        return sum;
    
        
        
    }
};
