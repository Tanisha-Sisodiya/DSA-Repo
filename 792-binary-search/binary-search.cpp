class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0;
        int right = nums.size();
        while(left < right){
            if(nums[left] == target){
                return left;
            }
            left++;
        }
        return -1;

        }

};