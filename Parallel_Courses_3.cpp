// Problem Link: https://leetcode.com/problems/parallel-courses-iii/

// INTUITION: Here the question is very simple, we can only do the next start if and only if it has no pending 
// prerequisites tasks.
// So from here intuition of topological sort strikes.

// What was i initially doing wrong.
// I thought that for every level of pre-requisites nodes i will take the maximum time among all of them and then move forward.
// which fails for some cases.

// Eg: Consider graph. 				
// 0 -> 4
// 1-> 4
// 2-> 3
// 3-> 4
// and time[node] = {20, 2, 3, 4, 5}

// We will 1st push nodes with indegree 0 i.e node: 0,1,2 => max time is of node 2 i.e 20 minutes.
// So what i was doing that i took maximum time among all these nodes first and then added it in my answer.
// after that next nodes that will be pushed in the queue are nods: 3. (according to toposort)
// then i took time[3] in my answer.
// After that node 4 got inserted in queue and i took time[4]. in my answer
// So my answer was coming : time[2] + time[3] +time[4] = 29.
// Which is wrong answer because expected answer is 25.

// We will have to think practically. 
// If node 2 takes mximum time among all its indegree nodes, in that time node 2 and node 3 would have already
// completed their task.
// Now all the nodes(1,2,3) are waiting for node 2 to complete it's task, then only we can proceed to node 4.
// So that means overall till this point we are waiting for 20 minutes only. and then we are going to node 4
// And for sure all the nodes will complete this task, in 5 minutes, but the overall time it took is 25 minutes.

// See one thing to observe from question is that all the nodes which have same indegree are completing task independently.
// And they can also work concurrenty, but can complete the next task only when all previous tasks, are completed.

// Just take the example and draw the graph you will come to know.

class Solution
{
public:
    int minimumTime(int n, vector<vector<int>> &relations, vector<int> &time)
    {
        vector<int> adj[n];
        for (int i = 0; i < relations.size(); i++)
        {
            adj[relations[i][0] - 1].push_back(relations[i][1] - 1);
        }
        vector<int> indeg(n, 0);
        for (int i = 0; i < n; i++)
        {
            for (auto &elem : adj[i])
            {
                indeg[elem]++;
            }
        }
        vector<int> waitTime(n, 0);
        
        queue<int> q;
        for (int i = 0; i < n; i++)
        {
            if (indeg[i] == 0)
            {
                q.push(i);
                waitTime[i] = time[i];
            }
        }

        int node = -1;
        while (!q.empty())
        {
            node = q.front();
            q.pop();

            for (auto &elem : adj[node])
            {
                waitTime[elem] = max(waitTime[elem], time[elem] + waitTime[node]);
                indeg[elem]--;
                if (indeg[elem] == 0)
                    q.push(elem);
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            ans = max(ans, waitTime[i]);
        }

        return ans;
    }
};