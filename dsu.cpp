#include<bits/stdc++.h>
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ll long long
using namespace std;
void init_code()
{
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif // ONLINE_JUDGE
}

// *************************************************************

// step 1 : make the class disjoint
// step2 : create parent and rank array to store the parent and rank
// step3 : if ranks are equal for u and v then increase the rank of any of them by 1
// step4 : findparent function to find the ultimate parent of that node using dfs

//  Time Compexity is  O(4*alpha) where alpha is close to 1.
// Note: a component with higher rank means it is greater in size or height
class Disjoint{

   vector<int> parent , rank ,size;

    public:
	
		// initalising the parent and rank.
		Disjoint(int n)
		{
			rank.resize(n+1 , 0);
			size.resize(n+1 , 1);
			parent.resize(n+1);
			for(int i=0 ; i <=n ;i++) parent[i] = i;
		}
        
        // find the ultimate parent for the node using dfs. also known
        // as Path compression where we link every node to its
        // ultimate parent
	    int findUParent(int node)
	    {
	    	if(parent[node] == node) return node;

	    	return parent[node]  = findUParent(parent[node]);

	    }

	    void UnionByRank(int u , int v)
	    {
              int pu = findUParent(u);
              int pv = findUParent(v);
               
               if(pu == pv) return;
               // if rank of node v < node u then attach node v to node u.
              if(rank[pv] < rank[pu])
              {
                   parent[pv] = pu;
              }
              // if rank of node u < node v then attach node u to node v.
              else if(rank[pu] < rank[pv])
              {
                   parent[pu] = pv;
              }
              else
              {
                   parent[pv] = pu;
                   rank[pu]++;  // if equal rank then increment rank by 1.
              }
	    }
        
        // union by size is more intutive as we are storing the size of the component  
        // at each step and the compnent with smaller size is attached to greater size 
        // component
	    void UnionBySize(int u , int v)
	    {
              int pu = findUParent(u);
              int pv = findUParent(v);
               
               if(pu == pv) return;

               if(size[pu] < size[pv])
               {
               	  parent[pu] = pv;
               	  size[pv]+=size[pu]; 
               }
               else if(size[pv] < size[pu])
               {
               	parent[pv] = pu;
               	size[pu]+=size[pv];  // size of component u + v
               }
               else
               {
               	 parent[pv] = pu;
               	 size[pu]+=size[pv]; 
               }
	    }
          
	    bool BelongToSameComponent(int u , int v)
	    {
	    	return findUParent(u) == findUParent(v);
	    }
	
};


int main()

{   init_code();

    Disjoint ds(7); // number of edges +1

    // ds.UnionByRank(1,2);
    // ds.UnionByRank(2,3);
    // ds.UnionByRank(4,5);
    // ds.UnionByRank(6,7);
    // ds.BelongToSameComponent(6,7) ? cout<<"belong to same component\n" : cout<<"not belong to same component\n";
    // ds.UnionByRank(5,6);
    //  ds.BelongToSameComponent(3,4) ? cout<<"belong to same component\n" : cout<<"not belong to same component\n";
   
    // ds.UnionByRank(3,7);
    // ds.BelongToSameComponent(3,7) ? cout<<"belong to same component\n" : cout<<"not belong to same component\n";
     
    ds.UnionBySize(1,2);
    ds.UnionBySize(2,3);
    ds.UnionBySize(4,5);
    ds.UnionBySize(6,7);
    ds.BelongToSameComponent(6,7) ? cout<<"belong to same component\n" : cout<<"not belong to same component\n";
    ds.UnionBySize(5,6);
     // ds.BelongToSameComponent(3,4) ? cout<<"belong to same component\n" : cout<<"not belong to same component\n";
   
    ds.UnionBySize(3,7);
    ds.BelongToSameComponent(3,7) ? cout<<"belong to same component\n" : cout<<"not belong to same component\n";
     
}


