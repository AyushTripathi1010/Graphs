// Problem Link: https://leetcode.com/problems/shortest-path-visiting-all-nodes/ 

// INTUITION: It is very important question as we will learn a new concept of using
// bitmasking ,and why to even use it in this question.

// The question want's us to find the shortest path to visit all the nodes, in undirected graph.
// Consider everry edge to be of 1 unit.
// But the catch in this question is that we can use a node and edge multiple
// times.
// Because it might be possible, that to get the shortest path we would have
// traverse edge multiple times.

// One thing is clear that we an not use conecpt of visited array, here directly,
// but if we do not use visited array concept , then we would be traversing
// an edge again and again.

// So we can use a bitmasking which will store the state of every node.
// Eg : graph ----->         
					//		 0
					//		/|\
					//	   / | \
					//	   1 2  3

// 
// if we start dfs from node 0, the shortest path covering all node is:
   // 0 --> 1-->0-->2-->0-->3, pathcount = 5.

// if we start dfs from node 1, the shortest path covering all node is:
   //  1-->0-->2-->0-->3, pathcount = 4.

// So from above one thing is clear that any node can give us the shortest path
// count, so we will use multisource bfs, i.e start dfs from every node.

// Now how bitmasking is helping to avoid situation of traversing again and again.
// ANs. For every node we are calculating the state and doing or tih it's previous node state
//  we will insert pair of {node, state} in our visited set.

// eg: 	0 --------> 1 ----------> 0 -------> 1
// 	   (0,0001)	  (1,0011)      (0,0011)    (1,0011) -> but this pair is already present in set
// which avoids us to push it into the queue.
// So what happen is that 0 --> 1, is a new path
//  1 --> 0 is a new path 
//  0 --> 1 is again the path with same state, we can only come to this path again
// if the state is different, i.e when we are coming from some other node.

// Finally when all nodes are covered, then all bits become set. And number of bits
// are equal to number of nodes.
// eg in above graph, total nodes = 4. , so final bits should be 1111, which
// is equal to 2^4 -1., then we will return.
class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
         set<pair<int,int>> visited; // node , path_mask
         queue<pair<int,int>> q; // node , path_mask

         for(int node = 0; node < n ; node++)
         {
                 int path_mask = (1<<node);
                 
                 q.push({node , path_mask});
                 visited.insert({node,path_mask});
         }

         int allVisitedState = (1<<n) - 1; 
         int path = 0;
         while(!q.empty())
         {   
             int sz = q.size();
             path++;
             for(int i = 0 ;i < sz ; i++)
             {
                int node = q.front().first;
                int path_vis = q.front().second;
                q.pop();
                
                for(auto &elem: graph[node])
                {
                    int next_node = elem;
                    int new_path_vis = (1<< next_node) | path_vis;

                    if(new_path_vis == allVisitedState) 
                    return path;

                    if(visited.find({next_node , new_path_vis}) == visited.end())
                    {
                        q.push({next_node, new_path_vis});
                        visited.insert({next_node , new_path_vis});
                    }

                }
             }
         }
          
          return 0;





    }
};