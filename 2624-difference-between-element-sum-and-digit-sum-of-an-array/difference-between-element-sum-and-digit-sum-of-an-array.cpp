class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        int sum1 = 0;
        int sum2 = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum1 += nums[i];
            int x = nums[i];
            int d = 0;
            while (x > 0) {
                d++;
                x /= 10;
            }
            for (int j = 0; j < d; j++) {
                sum2 += nums[i] % 10;
                nums[i] /= 10;
            }
        }
        if (sum1 > sum2) {
            return sum1 - sum2;
        }
        return sum2 - sum1;
    }
};