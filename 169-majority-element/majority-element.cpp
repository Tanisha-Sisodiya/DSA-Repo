class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int mid = nums.size()/2;
        unordered_map<int, int> mp;
        for(int i = 0; i<nums.size(); i++){
            mp[nums[i]]++;
            if(mp[nums[i]]>mid){
                return nums[i];
            }
        }  return {};
    }
};