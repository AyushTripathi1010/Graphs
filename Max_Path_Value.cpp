// Coding Ninjas Link: https: www.codingninjas.com/studio/problems/max-path-value_1082555

// Problem Statement: 
// You are given a directed graph with 'N' nodes and 'M' edges. 
// Each node has a lowercase letter assigned to it. For any path, 
// the path's value is defined as the maximum frequency of a letter on the path. 
// You are supposed to find the maximum value of a path. 
// If the maximum value can be infinitely large then return -1. 
// Example:
// If some path has the letters "xyxxxyzz" then the value of this 
 // path will be 4 as the maximum frequency of any letter('x') is 4.


 // INTUITION: One doubt may come up in the mind that in dfs code why are
// are we no using the condition, if(!vis[elme]) { dfs(); }, but directly 
// calling the dfs calls, for those nodes that are already visited, 

//  it is because we have to consider every path , possible, then
// only we can find the maximum occurence of an element in a path.

//  Supoose i travel a path and got maximum frequency of 'a' = 4, 
// but there can be some other path which is connected to any of the 
// nodes of this path, so we want to, consider this path also, even 
// if it contains visited element, becaise this is a new path, and we
//  a complete path.


// Why topoSort ?
  // So since it is a directed graph, and we greedily are looking for
// the longest paths so that we can acheive a maximum frequence, which
// can only happen if we do topo sort of elements.
#include <bits/stdc++.h> 

void dfs(int node , vector<int> adj[] , string &values , vector<int> &vis , vector<int>&freq , 
 int &ans)
{
    vis[node] = 1;
    freq[values[node-1] - 'a']++;
    ans = max(ans , freq[values[node-1] - 'a']);
    for(auto elem : adj[node])
    {
             // To consider all the paths we will not put the condition of if(!vis[elem])
            dfs(elem , adj , values, vis , freq , ans );
            
        
    }
     freq[values[node-1] - 'a']--;
    
}

bool isCyclic(int node , vector<int> adj[] , vector<int> &vis , vector<int> &pathvis)
{
    vis[node] = 1;
    pathvis[node] = 1;

    for(auto elem : adj[node])
    {
        if(!vis[elem])
        {
            if(isCyclic(elem , adj , vis , pathvis)) return true;
        }
        else if(vis[elem] && pathvis[elem])
        {
            return true;
        }
    }
    pathvis[node] = 0;
    
    return false;
}

vector<int> topoSort(vector<int> adj[] , int n)
{
    
    vector<int> indegree(n+1, 0);
    vector<int> ans;
    for(int i = 1; i<=n ; i++)
    {
         for(auto elem : adj[i])
         {
             indegree[elem]++;
         }
    }

    queue<int> q;
    for(int i =1 ; i <= n ; i++)
    {
        if(indegree[i] == 0) q.push(i);
    }

    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        
        ans.push_back(node);

        for(auto elem:  adj[node])
        {
            indegree[elem]--;

            if(indegree[elem] == 0) 
            q.push(elem);
        }

    }
    return ans;

}
int maxPathValue(int n, int m, vector<vector<int>> &edges, string &values) {
    // Write your code here.

    vector<int> adj[n+1];
    int ans=0;
    for(auto vec: edges )
    {
        adj[vec[0]].push_back(vec[1]);

    }

    //  Check whether there is cycle or not
       vector<int> vis(n+1 , 0);
       vector<int> pathvis(n+1, 0);
       for(int i =1 ; i <= n ; i++)
       {
           if(!vis[i])
           {
              if(isCyclic(i , adj , vis , pathvis)) 
              return -1;
           }
       }
       
    //     Now do a topo sort
          fill(vis.begin() , vis.end() , 0);
          vector<int> topo = topoSort(adj , n);
    
    vector<int> freq(26,0);
    for(int i = 0 ; i < topo.size() ; i++)
    {
        if(!vis[topo[i]])
        {
            dfs(topo[i] , adj , values , vis , freq , ans);
        }
    }

    return ans;

}