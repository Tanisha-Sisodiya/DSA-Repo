class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        for (int i = 1; i < nums.size() - 1; i++) {
        if(nums[i - 1] >= nums[i] && nums[i] <= nums[i + 1]){
            return false;
        }
            if (nums[i - 1] < nums[i] && nums[i] > nums[i + 1]) {
                for (int j = i + 1; j < nums.size() - 1; j++) {
                    if (nums[j - 1] > nums[j] && nums[j] < nums[j + 1]) {
                        for (int k = j + 1; k < nums.size() - 1; k++) {
                            if (nums[k - 1] <= nums[k] && nums[k] >= nums[k + 1]) {
                                return false;
                            }
                        }
                            return true;
                        }
                    }
                }
            }
            return false;
        }
    };