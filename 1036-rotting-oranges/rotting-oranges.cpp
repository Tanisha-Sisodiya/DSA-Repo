class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int ans = 0;
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<pair<int, int>, int>> Q;
        vector<vector<int>> vis(m, vector<int>(n, 0));
        int t = 0;
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
               if(grid[i][j] == 2){
                Q.push({{i, j}, t});
                vis[i][j] = 1;
               }
            }
        }
        
        while(!Q.empty()){
            int i = Q.front().first.first;
            int j = Q.front().first.second;
            int t = Q.front().second;
            Q.pop();

            ans = max(ans, t);
             
            if(i-1 >= 0 && !vis[i-1][j] && grid[i-1][j] == 1){
                Q.push({{i-1, j}, t+1});
                vis[i-1][j] = 1;
            }
            if(i+1 < m && !vis[i+1][j] && grid[i+1][j] == 1){
                Q.push({{i+1, j}, t+1});
                vis[i+1][j] = 1;
            }
            if(j-1 >= 0 && !vis[i][j-1] && grid[i][j-1] == 1){
                Q.push({{i, j-1}, t+1});
                vis[i][j-1] = 1;
            }
            if(j+1 < n && !vis[i][j+1] && grid[i][j+1] == 1){
                Q.push({{i, j+1}, t+1});
                vis[i][j+1] = 1;
            }
            
        }
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
               if(grid[i][j] == 1 && !vis[i][j]){
                return -1 ;      
               }
            }
        }
        return ans;
    }
};