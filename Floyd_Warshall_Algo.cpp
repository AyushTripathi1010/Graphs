// GFG LINK: https://practice.geeksforgeeks.org/problems/implementing-floyd-warshall2042/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=implementing-floyd-warshall


// INTUITION : in Floyd warshall algo, we need to find  shortest distances 
 // between every pair of vertices in a given edge-weighted directed graph.

//  TO acheive this we find the distance of each node via each node
// supoose in first iteration we will find the shortest distance
// to reach every node via 0th node.
// Then in 1st iteration we find the shortest distance to reach 
// every node via 1st node, and simlary till n nodes, and try 
// to update the distance for each node with the smallest
// distance we get.
class Solution {
  public:
	void shortest_distance(vector<vector<int>>&matrix){
	  
	    int n = matrix.size();
	   // first changing all the occurences of -1 in matrix to 1e9 .
	   
	   for(int i=0  ; i < n; i++)
	   {
	       for(int  j  =0 ; j < n ; j++)
	       {
	           if(matrix[i][j] == -1) matrix[i][j] = 1e9;
	       }
	   }
	   

	   for(int via = 0 ; via  <n ; via++)
	   {   
	       	// Traversing the matrix for each via node.
	       for(int i =0 ; i < n; i++)
	       {
	            for(int j= 0 ; j < n; j++)
	            {
	                matrix[i][j] = min(matrix[i][j] , matrix[i][via]+matrix[via][j]);
	            }
	       }
	   }
	   
	   
	   //  Again changing the occurence of 1e9 to -1, according 
	   // to the output asked.
	   for(int i=0  ; i < n; i++)
	   {
	       for(int  j  =0 ; j < n ; j++)
	       {
	           if(matrix[i][j] == 1e9) matrix[i][j] = -1;
	       }
	   }
	   
	   
	   
	   
	}
};