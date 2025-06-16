class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int m = accounts.size();
        int n = accounts[0].size();
        int maxWealth = 0 ;
        int Wealth;
        for(int i = 0; i<m; i++){
            Wealth = 0;
            for(int j = 0; j<n; j++){
                
                Wealth += accounts[i][j];
            
            }
            if(maxWealth < Wealth){
                maxWealth = Wealth;
            }
        }
        return maxWealth;
    }
};