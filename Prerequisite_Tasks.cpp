// GFG Link: https: practice.geeksforgeeks.org/problems/prerequisite-tasks/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=prerequisite-tasks

class Solution {
public:
	bool isPossible(int N,int P, vector<pair<int, int> >& prereq) {
	    // Code here
	    
	       int indeg[N] = {0};
	       vector<int> adj[N];
	       
	       for(auto vec : prereq)
	       {
	           adj[vec.first].push_back(vec.second);
	       }
	       
	       queue<int> q;
	       int cnt= 0 ;
	       for(int i = 0; i < N ; i++)
	       {
	           for(auto elem : adj[i])
	           indeg[elem]++;
	       }
	       
	       for(int i =0 ; i < N ; i++)
	       {
	           if(indeg[i] == 0) q.push(i);
	       }
	       
	       while(!q.empty())
	       {
	           int node = q.front();
	           q.pop();
	           cnt++;
	           
	           for(auto elem : adj[node])
	           {
	               indeg[elem]--;
	               if(indeg[elem] == 0) q.push(elem);
	           }
	       }
	       
	       if(cnt == N) return true;
	       return false;
	       
	       
	        
	}
};