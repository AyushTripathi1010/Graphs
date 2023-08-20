// LEETCODE LINK : https://leetcode.com/problems/maximal-network-rank/submissions/1026812296/ 


// INTUITION : we have to find pair of nodes which give the maximum
// network connection, that is we have to look for 2 nodes, which
// has maximum no. of directed edges connected to them.
// and then add the connections of both node together, 
// the only thing to look here is if the 2 nodes selected have
// an edges with each other, then we will count that edge only once
// so we will also be checking for condition if 2 nodes
// have edge, then decrement the duplicate occurence by subtracting
// 1. other wise don't do any thing.
// we have used unordered_set inside adjaceny list so that
// we can do find operation in O(1).

// T.C = O(V^2)
class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
            
            //  adjacency list.
            unordered_map<int, unordered_set<int>> adj;

            for(auto vec : roads)
            {
                adj[vec[0]].insert(vec[1]);
                adj[vec[1]].insert(vec[0]);
            }
            
             int ans= 0 ;
            for(int i= 0 ; i < n; i++)
            {
                for(int j = i+1 ; j < n ; j++)
                {
                    int rank_i = adj[i].size();
                    int rank_j = adj[j].size();

                    int rank = rank_i + rank_j;
                      
                    //   if there is edge between i and j node
                    if(adj[i].find(j) != adj[i].end())
                    rank--;

                    ans = max(ans , rank);    
                    
                }
            }        

            return ans;
    }
};