// GFG LINK : https://practice.geeksforgeeks.org/problems/city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=city-with-the-smallest-number-of-neighbors-at-a-threshold-distance


//  INTUITION : we are apllying floyd warshall to get the smallest
// distance between every pair of vertex , because in question 
// we have to find a city or node which has smallest number of 
// nodes reachable to it with distance smaller than threshold
//  so floyd automatically gives smallest distance between vertices.

class Solution {
  public:
    int findCity(int n, int m, vector<vector<int>>& edges, int distanceThreshold) 
    {    

        vector<vector<int>> distance(n , vector<int> (n, 1e9));

        // Making the cost matrix 
        for(auto vec : edges)
        {
            distance[vec[0]][vec[1]] = vec[2];
            distance[vec[1]][vec[0]] = vec[2];
        }

        //  Marking the diagonals as 0. eg: to reach 1 to 1 = 0.
        for(int i = 0 ;i < n ; i++) distance[i][i] = 0;
        
        // finding shortest distance between every pair of
        //  vertex.
        for(int via = 0; via < n ; via++ )
        {
            for(int i = 0 ; i < n ; i++)
            {
                for(int j = 0 ; j < n; j++)
                {
                    distance[i][j] = min(distance[i][j] , distance[i][via]+distance[via][j]);
                }
            }
        }
        
        
        // initially assuming the citymax = number of nodes.
        int citymax = n;
        
        int city = -1;

        // outer loop to check which city is the answer.
        for(int i =0  ;i < n ; i++)
        {  
            int cnt=0;

            // checking how many cities are reachable to 
            // city i with distance smaller than threshold.
            for(int j = 0 ; j < n ;j++)
            {
                if(distance[i][j] <= distanceThreshold)
                {
                    cnt++;
                }
            }
            
            if(cnt <= citymax)
            {
                citymax = cnt;
                city = i;
            }
        }
        
       return city;
    }
};