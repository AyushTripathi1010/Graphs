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




// INTUITION : So here the question is saying that we have to 
// merge nodes with same account that means if 2 nodes
// have same mail then merge the nodes into 1 component
// and also 2 people can have same name , 
// but we have to merger on the basis of
// same account name.
// so if 2 people have same account name this means
// they are same people.





class Disjoint
{
	vector<int> parent, size;

public:

	      Disjoint(int n)
	      {
	      	 size.resize(n+1 , 0);
	      	 parent.resize(n+1);

	      	 for(int i = 0; i < parent.size() ; i++)
	      	 	parent[i] = i;


	      }

	// to find the ultimate parent of a node using dfs

	 int findUParent(int node)
	 {
	 	  if(parent[node] == node) return node ;   // returning the ultimate parent in the base case

	 	  return parent[node] = findUParent(parent[node]);  // and after returning storing the ultimate parent in each node called

	 }

	 // to find the union size

	 void UnionSize(int u , int v)
	 {
	 	int pu = findUParent(u);
	 	int pv = findUParent(v);

	 	if(pu == pv) return;

	 	if(size[pu] > size[pv])
	 	{
              parent[v] = pu;
	 	}
	 	else
	 	{
	 		parent[u] = pv;
	 	}
	 }

	 bool BelongToSameComponent(int u , int v)
	 {
	 	 return findUParent(u) == findUParent(v);
	 }



};

class Solution
{
    public:
  vector<vector<string>> accountsMerge(vector<vector<string>> &accounts)
{
       // number of nodes
       int n = accounts.size();
       
       // this will iniitalise parent and size array with size of n.
       Disjoint ds(n); 

       unordered_map<string,int> m;

       for(int i= 0 ; i<n ; i++)
       {
       	for(int j = 1  ;j < accounts[i].size(); j++)
       	{
       		  string mail = accounts[i][j];
            // here if mail is not present in map then assign the mail with its corressponding node
       		  if(m.find(mail) == m.end())
       		  {
       		  	  m[mail] = i;
       		  }
       		//  if it is present then connect it to its ultimate parent node.
       		  else
       		  {
       		  	  ds.UnionSize(j , m[mail]);
       		  }
       	}
       }


       
       // So are now going to store all the mails that belong
       // to same nodes.
       // Coressponding to every node we storing the mails.
       // and if suppose 2 nodes have same mail then we will 
       // call dsu and join them. 
       vector<string> mergeMail[n];

       for(auto it:  m)
       {
       	 string mail = it.first;
       	 int mail_node  = ds.findUParent(it.second);

       	 mergeMail[mail_node].push_back(mail);
       }


        // Now we will iterate over mergedMails for every node
       // and corresponding to every node we will sort the
       // string of mails in ascending order.
       // and suppose if a node doesn't have any mail associated with 
       // it then we won't include it in our answer.
       vector<vector<string>> ans;
       
       for(int i = 0; i < n ; i++)
       {
       	  if(mergeMail[i].size() == 0) continue;

       	  sort(mergeMail[i].begin() , mergeMail[i].end());
           
           vector<string> temp;
           
           // in our answer we first want the name.
           temp.push_back(accounts[i][0]);
            

           for(auto elem : mergeMail[i])
           {
           	 temp.push_back(elem);
           }

           ans.push_back(temp);

       }

       return ans;
}

};

int main()
{    init_code();
	vector<vector<string>> accounts =
{{"John","johnsmith@mail.com","john_newyork@mail.com"},
{"John","johnsmith@mail.com","john00@mail.com"},
{"Mary","mary@mail.com"},
{"John","johnnybravo@mail.com"}};
    
   Solution obj1;

   vector<vector<string>> ans  = obj1.accountsMerge(accounts);




   
   for(auto vec: ans)
    {
    	for(auto elem : vec)
    	{
    		cout<<elem<<" ";
    	}
    	cout<<"\n";
    }
    

}