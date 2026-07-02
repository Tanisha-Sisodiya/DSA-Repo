class Solution {
public:
    int m, n;
    void dfs(vector<vector<char>>& grid,vector<vector<bool>>&vis,int i,int j ){

        vis[i][j] = true;
        if(i-1 >= 0 && grid[i-1][j]== '1' && !vis[i-1][j]){
            dfs(grid, vis, i-1, j);
        }
        if(j-1 >= 0 && grid[i][j-1]== '1' && !vis[i][j-1]){
            dfs(grid, vis, i, j-1);
        }
        if(i+1 < n && grid[i+1][j]== '1' && !vis[i+1][j]){
            dfs(grid, vis, i+1, j);
        }
        if(j+1 < m && grid[i][j+1]== '1' && !vis[i][j+1]){
            dfs(grid, vis, i, j+1);
        }
        return;
    }
    int numIslands(vector<vector<char>>& grid) {
        n = grid.size();
        m = grid[0].size();

        vector<vector<bool>> vis(n, vector<bool> (m, false));
        int ans = 0;

        for(int i = 0; i< n; i++){
            for(int j = 0; j<m ; j++){
                if(grid[i][j]== '1' && !vis[i][j]){
                    dfs(grid, vis, i, j);
                    ans++;
                }
            }
        }
        return ans;
    }
};