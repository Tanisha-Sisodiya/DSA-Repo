class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));

        queue<pair<int,int>> q;
        q.push({sr, sc});
        vis[sr][sc] = 1;
        int x = image[sr][sc];
        image[sr][sc] = color;

        while(!q.empty()){
            int i = q.front().first;
            int j = q.front().second;
            q.pop();

            if(i-1 >= 0 && image[i-1][j] == x && !vis[i-1][j]){
                image[i-1][j] = color;
                vis[i-1][j] = 1;
                q.push({i-1,j});
            }
            if(j-1 >= 0 && image[i][j-1] == x && !vis[i][j-1]){
                image[i][j-1] = color;
                vis[i][j-1] = 1;
                q.push({i,j-1});
            }
            if(i+1 < n && image[i+1][j] == x && !vis[i+1][j]){
                image[i+1][j] = color;
                vis[i+1][j] = 1;
                q.push({i+1,j});
            }
            if(j+1 < m && image[i][j+1] == x && !vis[i][j+1]){
                image[i][j+1] = color;
                vis[i][j+1] = 1;
                q.push({i,j+1});
                
            }
        }

        return image;

    }
};