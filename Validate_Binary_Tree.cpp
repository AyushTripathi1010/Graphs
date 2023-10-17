// Problem Link: https://leetcode.com/problems/validate-binary-tree-nodes/


// INTUITION: here we have to check whether the following tree is valid binary tree or not using the leftChild and rightChild array.
// A tree is invalid if:
// 1. If there a more than 1 root nodes, because a valid tree has only one root node which has indegree of 0.
// 2. A node should not have more than one parent or indegrees, because every node of tree has only parent except root node.
// 3. There should be no cycle in the tree, and also it should not have more than one component.
// So we will check for cycles.
class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
            
            //  Create adjacency list
            vector<int> adj[n];
            
            for(int i= 0; i < n ; i++)
            {
                if(leftChild[i] != -1) adj[i].push_back(leftChild[i]);

                if(rightChild[i] != -1) adj[i].push_back(rightChild[i]);
            }

            // find the indegree's for all nodes.
            vector<int> indeg(n , 0);
            for(int i= 0 ; i < n ; i++)
            {
                for(auto &elem : adj[i])
                {
                    indeg[elem]++;
                }
            }

            queue<int> q;
            for(int i =0 ; i < n ; i++)
            {
                if(indeg[i] == 0) q.push(i);
                
                // if a node has more than 1 parent or indegree.
                if(indeg[i] > 1) return false;
            }

            if(q.size() != 1) return false; // if thre are more than 1 root.

            // Now check if there is a cycle or more than 1 components then also it 
            // not a valid binary tree.
            int cnt =0 ;
            while(!q.empty())
            {
                int node = q.front();
                q.pop();
                cnt++;
                
                for(auto &elem : adj[node])
                {
                    indeg[elem]--;
                    if(indeg[elem] == 0)
                    q.push(elem);

                }
            }
            return cnt == n;


    }
};