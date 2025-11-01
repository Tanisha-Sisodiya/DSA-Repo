class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        vector<int> ans;
        unordered_map<int,int> mp;

        for(int i = 0; i< nums.size(); i++){
            mp[nums[i]]++;
        }
        for(int i = 0; i< nums.size(); i++){
            if(mp[nums[i]]==2) ans.push_back(nums[i]);
            mp[nums[i]] = 0;
        }
        return ans;
    }
};