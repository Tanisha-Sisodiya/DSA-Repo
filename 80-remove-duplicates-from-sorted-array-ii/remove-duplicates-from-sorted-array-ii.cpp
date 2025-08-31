class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        for(int i = nums.size()-1; i>1; i--){
            if(nums[i] == nums[i-2]){
                for(int j = i; j<nums.size()-1; j++){
                    nums[j] = nums[j+1];
                }
                n--;
            }
        }
        return n;
    }
};