// GFG LINK: https://practice.geeksforgeeks.org/problems/minimum-multiplications-to-reach-end/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=minimum-multiplications-to-reach-end 

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        // code here
        int MOD = 1e5;
        queue<pair<int,int>> q;
        
        q.push({0 , start}); // dist , node
       
        vector<int> distance(100000, 1e9);
        
        distance[start] = 0;
        // Edge case, as this condition will not be checked in the queue.
        if(start == end) return 0;
        while(!q.empty())
        {
            int node = q.front().second;
            int steps = q.front().first;
            q.pop();
            
            for(auto elem : arr)
            {
                int num = (elem * node)%MOD;
                
                // + 1 is done to add unit step or distance.
                if( distance[node] + 1 < distance[num])
                {
                    distance[num] = distance[node]+1;
                    q.push({distance[num], num});
                    
                    
                    if(num == end) return distance[num];
                }
            }
        }
        return -1;
    }
};
