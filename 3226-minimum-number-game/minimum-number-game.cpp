class Solution {
public:
    vector<int> numberGame(vector<int>& nums) {

        vector<int> arr;
        int index;
        int n = nums.size();
        for (int j = 0; j < n; j++) {
            int min = INT_MAX;
            for (int i = 0; i < nums.size(); i++) {
                if (min > nums[i]) {
                    min = nums[i];
                    index = i;
                }
            }
            arr.push_back(min);
            nums.erase(nums.begin() + index);

            for (int i = 0; i < arr.size() - 1; i += 2) {
                swap(arr[i], arr[i + 1]);
            }
        }
        return arr;
    }
};