// LEETCODE LINK: https://leetcode.com/problems/sort-items-by-groups-respecting-dependencies/

// INTUITION : Here in the question we have group array
// which tells to which grp does an item belong to.
// so an ith item belongs to group[i]. There may be some items
// assigned with group[i] = -1, which suggest that particular
// item does not belong to any group, so we will give it a group
// number by ourselves.

// There is a beforeItems list of list which tells that for 
// ith item which all nodes come before it in the ordering
// so if before[2] = {3,4}, which means that item 3 and 4 come
// before item 2 in the final ordering.

// The question also says that the items in same group should
// be next to each other or adjacent to each other.

// We can conclude that ordering not only depends on beforeItems
// but also depends on group ordering.

// So to satisfy both the conditions we will make 2 graphs, 
// one for item ordering based on beforeItems list of list.
// and second for group ordering only.

// HOW TO GET THE GROUP ORDERING.	
// So we will iterate over every item in group array and check for it's group
// number, and simultaneously we will also look in corresponding
// index in beforeItems array. and check which item in beforeItems list
// is before the currentItem in group array, if both don't belong
// to same grp then we will connect prevItemGrp --> CurrentItemGrp.

class Solution {
public:
    
    vector<int> Topo(vector<int> adj[] , vector<int> &indegree)
    {
        
        vector<int> ans;
        int n = indegree.size();
        queue<int> q;

        for(int i = 0; i < n ; i++)
        {
            if(indegree[i] == 0) q.push(i);
        }

        while(!q.empty())
        {
            int node = q.front();
            q.pop();

            ans.push_back(node);

            for(auto elem  : adj[node])
            {
                indegree[elem]--;

                if(indegree[elem] == 0) q.push(elem);
            }

        }
          
          // if topo sort is not possible, then return empty list.
        return ans.size() == n ? ans : vector<int>() ;
    }
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {

        // Step - 0 : assign the node with no group to some group number greater
        // than equal to m

        for(int i =0 ; i < n; i++)
        {
            if(group[i] == -1)
            {
                group[i] = m++;
            }
        }
          
           vector<int> itemIndegree(n , 0);
           vector<int> grpIndegree(m , 0);

        //  Step-1 : create item list graph
        //  the item graph is made on the basis of beforeItems
        //  list which tells us which node should come before which
        //  one.
                vector<int> itemAdj[n];
             for(int i =0 ; i< n ; i++)
             {
                 
                 int currentItem = i;

                 for(int &prevItem : beforeItems[currentItem])
                 {
                     itemAdj[prevItem].push_back(currentItem);    // PrevItem --> currentItem
                     itemIndegree[currentItem]++;
                 }
             }


        //  Step-2 : create group ordering graph, this group graph is
        //  made on the basis of group list and beforeItem List.

               vector<int> groupAdj[m];

               for(int i =0 ; i < n; i++)
               {   
                  

                   int CurrentGrp = group[i]; // Current Item grp.
                   
                   for(int &items : beforeItems[i])
                   {
                       int PrevGrp = group[items];  // grp number of item whcih is before currentItem

                       //  If they are not in same grp then
                       // connect, because if they are in same grp, then
                       // that case will automatically be handled by items ordering graph.
                       if(CurrentGrp != PrevGrp)
                       {
                           groupAdj[PrevGrp].push_back(CurrentGrp);   // PrevGrp --> CurrentGrp
                           grpIndegree[CurrentGrp]++;
                       }
                   }
               }

            //    Step - 3: Do Topo Sort for iteem ordering and group ordering
                  
                  vector<int> itemTopo = Topo(itemAdj , itemIndegree);
                  vector<int> grpTopo = Topo(groupAdj , grpIndegree);
                  
           
        //    Step - 4: Now iterate it itemTopo and put them according to
        //    their grpTopo ordering.
              
              // making GrpToItems map for storing items
              // int their respective grp.
               unordered_map<int , vector<int> > GrpToItems;

               for(int &items : itemTopo)
               {
                   int ItemGrp = group[items];
                   GrpToItems[ItemGrp].push_back(items);
               }
                  
                 // Since we have the item ordering with us
                 //  we will iterate over GrpTopo and corressponding
                 // to every grp insert all the nodes in the result vector.

                vector<int> result;
                for(int &grp : grpTopo)
                {
                    result.insert(result.end() , GrpToItems[grp].begin() , GrpToItems[grp].end() );
                }
                   
                   return result;

            
    }
};