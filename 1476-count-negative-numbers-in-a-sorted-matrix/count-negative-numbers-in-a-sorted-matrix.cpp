class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int ans = 0;
        for(int i = 0; i<grid.size(); i++){
            int j = 0;
            while(j<grid[i].size() && grid[i][j] >= 0 ){
                j++;
            }
            ans+= grid[i].size()-j;
        }
        return ans;
    }
};