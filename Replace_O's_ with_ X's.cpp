// User function Template for C++

class Solution{
public:
  void dfs(int row, int col , vector<vector<int>> &vis ,  vector<vector<char>>&mat, int n, int m , int *delrow, int *delcol)
  {
      vis[row][col] = 1;
      
       for(int i = 0; i<4 ; i++)
                 {
                     int nrow = row + delrow[i];
                     int ncol = col + delcol[i];
                     
                     if(nrow >=0 && nrow < n && ncol>=0 && ncol<m && mat[nrow][ncol] == 'O' && !vis[nrow][ncol])
                     {
                          dfs(nrow, ncol , vis ,mat,n,m,delrow,delcol);
                     }
                 }
  }
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        // code here
        vector<vector<char>> ans = mat;
        
        vector<vector<int>> vis(n , vector<int> (m , 0));
        int delrow[] = {0, 1, 0, -1};
         int delcol[] = {1, 0, -1, 0};
        
        // cover all the boundaries
         
        //  First Row
        for(int i= 0 ; i < m ; i++)
        {
            if(mat[0][i] == 'O' && !vis[0][i])
            {
                dfs(0, i, vis, mat,n,m,delrow,delcol);
            }
            
        }
        
        // Last Row
        for(int i= 0 ; i < m ; i++)
        {
            if(mat[n-1][i] == 'O' && !vis[n-1][i])
            {
                dfs(n-1, i, vis, mat,n,m,delrow,delcol);
            }
            
        }
        
        // First Column
        for(int i= 0 ; i < n ; i++)
        {
            if(mat[i][0] == 'O' && !vis[i][0])
            {
                dfs(i, 0, vis, mat,n,m,delrow,delcol);
            }
            
        }
        
        // Second Column
        for(int i= 0 ; i < n ; i++)
        {
            if(mat[i][m-1] == 'O' && !vis[i][m-1])
            {
                dfs(i, m-1, vis, mat,n,m,delrow,delcol);
            }
            
        }
        
        for(int i= 0 ;i < n ; i++)
        {
            for(int j = 0; j <m ; j++)
            {
                if(mat[i][j] == 'O' && !vis[i][j])
                ans[i][j] = 'X';
            }
        }
        
        return ans;
        
        
    }
};