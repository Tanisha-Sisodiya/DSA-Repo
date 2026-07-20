class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int temp;
        int prev;
        if(n*m == k) return grid;
        while (k--) {
            temp = grid[m - 1][n - 1];
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    prev = temp;
                    temp = grid[i][j];
                    grid[i][j] = prev;
                }
            }
        }

        return grid;
    }
};