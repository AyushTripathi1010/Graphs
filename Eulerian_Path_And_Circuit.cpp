// Problem Link: https://practice.geeksforgeeks.org/problems/euler-circuit-and-path/1

// INTUITION: Eulerian Path is a path in graph that visits every edge exactly once. 
// Eulerian Circuit is an Eulerian Path which starts and ends on the same vertex.

// So to find an Eulerian Path, the graph should have exactly 2 nodes with odd degress, i.e odd edges connected to that node.
// To check for Eulerian Circuit, the graph should have no Odd degrees.

class Solution {
public:
	int isEularCircuit(int V, vector<int>adj[]){
	    int cnt_Odd=0;
	    for(int i= 0 ; i < V ; i++)
	    {
	        if(adj[i].size()%2)
	        {
	            cnt_Odd++;
	        }
	        
	    }
	    
	    if(cnt_Odd == 0) // Euler Path
	    return 2;
	    
	    if(cnt_Odd == 2) // Euler Circuit
	    return 1;
	    
	    return 0; // None of the above.
	}
};
