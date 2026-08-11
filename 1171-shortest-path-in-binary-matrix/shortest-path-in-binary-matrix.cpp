class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0] == 1 || grid[n-1][n-1] == 1){
            return -1;
        }
        vector<vector<int>> dis(n, vector<int>(n, INT_MAX));
        queue<pair<int , pair<int,int>>>q;
        dis[0][0] = 1;
        q.push({1,{0,0}});
        while(!q.empty()){
            int d = q.front().first;
            int r = q.front().second.first;
            int c = q.front().second.second;
            q.pop();
            int dr[] = {-1, -1, -1, 0, 0, 1, 1, 1};
            int dc[] = {-1, 0, 1, -1, 1, -1, 0, 1};
            for(int i = 0; i<8; i++){
                int x = r+dr[i];
                int y = c+dc[i];
                if(x>=0 && y>=0 && x<n && y<n && dis[x][y] > d+1 && grid[x][y] == 0){
                    dis[x][y] = d+1;
                    q.push({d+1, {x,y}});
                    
                }
            }
            
        }
        if(dis[n-1][n-1]==INT_MAX)
        return -1;
        
        return dis[n-1][n-1];
    }
};