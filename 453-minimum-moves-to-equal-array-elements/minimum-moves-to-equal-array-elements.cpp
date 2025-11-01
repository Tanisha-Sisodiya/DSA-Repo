class Solution {
public:
    int minMoves(vector<int>& nums) {
        int min = INT_MAX;
        for(int i = 0; i<nums.size(); i++){
            if(min > nums[i]){
                min = nums[i];
            }
        }
        int ans = 0;
        for(int i = 0; i< nums.size(); i++){
            ans += nums[i] - min;
        }
        return ans;
    }
};