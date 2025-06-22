class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;

        while (left < right) {
            int mid = left + (right - left) / 2;

            // Make mid even
            if (mid % 2 == 1) mid--;

            // Check if this pair is valid
            if (nums[mid] == nums[mid + 1]) {
                // Unique element is after this pair
                left = mid + 2;
            } else {
                // Unique element is before or at mid
                right = mid;
            }
        }
        return nums[left];
    }
};
