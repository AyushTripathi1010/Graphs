
// GFG LINK: https://practice.geeksforgeeks.org/problems/course-schedule/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=course-schedule

class Solution
{
  public:
    vector<int> findOrder(int N, int m, vector<vector<int>> p) 
    {
        //code here
        vector<int> adj[N];
	    
	    for(int i =0 ; i< p.size(); i++)
	    {
	        adj[p[i][1]].push_back(p[i][0]);
	    }
	    
	    vector<int> indegree(N,0);
	    
	    for(int i = 0 ; i < N ;i++)
	    {
	        for(auto elem : adj[i])
	        {
	            indegree[elem]++;
	        }
	    }
	    
	    queue<int> q;
	    
	    for(int i =0 ; i <N ; i++)
	    {
	        if(indegree[i]== 0) q.push(i);
	    }
	      vector<int> topo;
	    while(!q.empty())
	    {
	        int elem = q.front();
	        q.pop();
	        
	        topo.push_back(elem);
	        
	        for(auto it: adj[elem])
	        {
	            indegree[it]--;
	            if(indegree[it] ==0)
	            q.push(it);
	        }
	    }
	    
	    if(topo.size()== N) return topo;
	    // if not possible to complete all tasks means there is a cycle 
	    //  so return empty array.s
	    return {};
	    
    }
};