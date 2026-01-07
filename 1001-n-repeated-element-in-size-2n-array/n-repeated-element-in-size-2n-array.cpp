class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_map<int, int> ans;
        for(int i = 0; i< nums.size(); i++){
            ans[nums[i]]++;
        }
        for(int j = 0; j<nums.size(); j++){
            if(ans[nums[j]] == (nums.size())/2) return nums[j];
        }
        return 0;
    }
};