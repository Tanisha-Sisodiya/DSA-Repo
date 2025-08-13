class Solution {
public:
    int minimumOperations(vector<vector<int>>& grid) {
        int op = 0;
        int m = grid.size();
        int n = grid[0].size();
        for(int j = 0; j<n; j++){
            for(int i = 0; i<m-1; i++){
                if(grid[i][j]>=grid[i+1][j]){
                    op += grid[i][j] - grid[i+1][j] + 1;
                    grid[i+1][j] += (grid[i][j] - grid[i+1][j] + 1);
                }
            }
        }
        return op;
    }
};