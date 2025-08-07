class Solution {
public:
    long long maximumMedianSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        long long sum = 0;
        
        for(int i = nums.size()-1; i>=(nums.size()/3); i-=2){
            sum += nums[i-1];
        }
        return sum;
    }
};