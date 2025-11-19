class Solution {
public:
    int Answer(const vector<int>& nums, int original) {
        for (int x : nums) {
            if (x == original) {
                return Answer(nums, original * 2);
            }
        }
        return original;
    }

    int findFinalValue(vector<int>& nums, int original) {
        return Answer(nums, original);
    }
};
