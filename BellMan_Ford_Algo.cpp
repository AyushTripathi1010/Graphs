// GFG LINK : https://practice.geeksforgeeks.org/problems/distance-from-the-source-bellman-ford-algorithm/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=distance-from-the-source-bellman-ford-algorithm


// INTUITION : This algorithm is different from dijkstra, in the sense
//  that bellman ford can also handle negative cycles, 
//  while dijkstra algo can't handle.

//  The edges can be given in any order.
// We iterate for N-1 times , because in worst case it can take
// N-1 edges to reach the last node, 
//  eg: 0 -> 1 -> 2 -> 3 -> 4, in this graph it will take 
// 4 iterations to calculate the shortest distances.

// To check for negative cycle we do Nth iteration seperately.

// In the N-1th iteration , we get all the shortest distances
// for every vertex from start node, but even after N th iteration
//  we are able to decrease the distance of a particular node
// then there is a negative cycle.


//  WHy used distance[node] != 1e8 in the if condition:
// -------------------ans----------------------------------
// The reason distance[node] != 1e8 is used as a condition is to
 // ensure that we only update the distance for nodes that have 
 // been reached and have valid distance estimates. Nodes with an 
 // itial distance of 1e8 are treated as if they are unreachable or
 // ot yet visited.

// By using this condition, the algorithm ensures that it doesn't
 // accidentally update distances for nodes that haven't been
 // visited yet, which could lead to incorrect results. 
 // It's a way of keeping track of whether a node's distance has 
 // een updated in the current iteration of the algorithm.


class Solution {
  public:
    /*  Function to implement Bellman Ford
    *   edges: vector of vectors which represents the graph
    *   S: source vertex to start traversing graph with
    *   V: number of vertices
    */
    vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
        // Code here
        
        vector<int> distance(V , 1e8);
        distance[S] = 0;
        
        // iterate for V - 1 edges
        
        for(int i= 0 ; i< V-1 ; i++)
        {
            for(auto vec:  edges)
            {    
                int u = vec[0];
                int v = vec[1];
                int wt = vec[2];
                
                if(distance[u]!= 1e8 &&   distance[u] + wt < distance[v])
                {
                    distance[v] = distance[u] + wt; 
                }
            }
        }
        
        //  Nth iteration for checking the negative cycle
           
           for(auto vec : edges)
           {
               int u = vec[0];
               int v = vec[1];
               int wt = vec[2];
               
               if(distance[u] != 1e8 && distance[u] + wt < distance[v])
               {
                   return {-1};
               }
               
           }
           
           return distance;
    }
};