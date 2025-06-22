class Solution {
public:
    int search(vector<int>& nums, int target) {
        int k = 0;
        int n = nums.size();

        // Step 1: Find rotation pivot (smallest element index)
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] > nums[i + 1]) {
                k = i + 1;
                break;
            }
        }

        // Step 2: Binary search in the rotated array (without modifying the array)
        int left = 0, right = n - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            // Adjusted mid to account for rotation
            int realMid = (mid + k) % n;

            if (nums[realMid] == target) return realMid;

            if (nums[realMid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return -1;
    }
};
