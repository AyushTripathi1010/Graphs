class Solution {
public:
    int n, m;
    int selcol;
    void dfs(int row, int col , vector<vector<int>> &ans, int &newColor, int* delrow, int *delcol)
    {
        ans[row][col] = newColor;
        
        for(int i =0 ; i < 4; i++)
        {
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];
            
            if(nrow >=0 && nrow < n && ncol>=0 && ncol<m  && ans[nrow][ncol] == selcol)
            {
                dfs(nrow, ncol , ans, newColor , delrow, delcol);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        // Code here 
          
          
          n = image.size();
          m = image[0].size();
        vector<vector<int>> ans(n , vector<int>(m));
          selcol = image[sr][sc];
          if(newColor == selcol) return image;
          int delrow[] = {0, 1, 0, -1};
          int delcol[] = {1, 0, -1, 0};
        for(int i =0 ; i < n ; i++)
        {
            for(int j = 0; j < m ; j++)
            {
                ans[i][j] = image[i][j];
            }
        }
        
        dfs(sr , sc, ans , newColor, delrow, delcol);
        
        return ans;
        
    }
};