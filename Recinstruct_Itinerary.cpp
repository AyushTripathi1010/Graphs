// Problem Link: https://leetcode.com/problems/reconstruct-itinerary/


// INTUITION : this questions uses the concept of eulerian circuit, where 
// the stations or nodes can have multiple edges between themselves, even
// cycles, and we have to print the lexical path, which covers all the edges,
// which in this case is tickets, and each edges must be traversed only once.

// SO here we can't use visited array, because even if a node is visited, still
// we will have to visit that node until all the edges in that node's adjaceny list
// don't get exhausted.
// So since a node can have multiple neighbours, we will have to visit every neighbour,
// if possible, via moving in a path.

// Since we want lexical order of path, therefore we are sorting each, adjacency
// neighbor.

// You may ask if once an edge has been visited and deleted from the adjaceny
// then why are we again inserting it back, while backtracking.
// It is because, it might be possible that while moving through a path, 
// we are not able visit every edge.
// Eg: Assume list : JKL -> PQR, ABC, SOJ, TRS.
// Now if suppose we took edge JKL->PQR, and later we found that we can't explore
// all the edges, but it might be possible that TRS can lead to JKL again and assume that 
// finally one node is remaining in JKL list, and that is PQR, which will get 
// visited and hence give answer.
// SO if we didn't had restored PQR in inital stages, so the later dfs calls
// would have got impacted, as PQR would not have been there, and hence
// we could nor have explored all the edges.
class Solution {
public:
    int N;
    vector<string> path;
    bool dfs(string fromAirPort, unordered_map<string, vector<string>> &adj)
    {    
         path.push_back(fromAirPort);
         if(path.size() == N+1)
         {
             return true;
         }
          
         vector<string> &neighbors  =  adj[fromAirPort];
         for(int i =0 ; i < neighbors.size() ; i++)
         {   
             
             string toAirPort = neighbors[i];
             neighbors.erase(neighbors.begin() + i);
             if(dfs(toAirPort , adj)) return true;
             neighbors.insert(neighbors.begin() + i , toAirPort);

         }
         path.pop_back();

         return false;
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, vector<string> > adj;

         N = tickets.size();
        for(auto &ticket : tickets)
        {
            adj[ticket[0]].push_back(ticket[1]);
        }

        for(auto &edge : adj)
        {
            sort(edge.second.begin() , edge.second.end());
        }


        dfs("JFK",adj );

        
        return path;

    }
};