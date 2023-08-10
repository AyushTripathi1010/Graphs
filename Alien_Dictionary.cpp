
// GFG Link : https://practice.geeksforgeeks.org/problems/alien-dictionary/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=alien-dictionary
class Solution{
    public:
    string findOrder(string dict[], int N, int K) {
        //code here
        vector<int> adj[K];

        //  Here the question states that the words is already sorted
        //  in alien dictionary so, to make a graph out of it
        //  we will,  compare 2 consecutive words and see which letter
        //  comes first.
        //  eg: baa , abcd, so by comparing these 2 words we can see that
        //  b comes before a, then we will break the comparision .

        for(int i = 0; i< N-1 ; i++)
        {
            string s1 = dict[i];
            string s2 = dict[i+1];
            
            //  Making the graph
            for(int i= 0 ; i< s1.size() && i<s2.size(); i++)
            {
                if(s1[i] != s2[i])
                {
                    adj[s1[i] -'a'].push_back(s2[i]- 'a');
                    break;
                }
            }
        }
         
         // Since the graph is now ready we can apply our topo sort.
        string topo;
        
        vector<int> indeg(K, 0);
        
        for(int i = 0 ; i < K ; i++)
        {
            for(auto elem : adj[i])
            {
                indeg[elem]++;
            }
        }
        
        queue<int> q;
        
        for(int i = 0; i < K ; i++)
        {
            if(indeg[i] == 0) q.push(i);
        }
        
        while(!q.empty())
        {
            int node = q.front();
            topo.push_back(node + 'a');
            q.pop();
            
            for(auto elem : adj[node])
            {
                indeg[elem]--;
                if(indeg[elem] == 0) q.push(elem);
            }
        }
        
           return topo;
        
    }
};