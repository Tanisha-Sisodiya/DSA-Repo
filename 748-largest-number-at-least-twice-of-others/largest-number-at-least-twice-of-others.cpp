class Solution {
public:
    int dominantIndex(vector<int>& nums) {
    int largest = nums[0];
    int second = -1;
    int x = 0;

    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] > largest) {
            second = largest;
            largest = nums[i];
            x = i;
        }
        else if (nums[i] < largest && nums[i] > second) {
            second = nums[i];
        }
    }
    if(largest >= 2*second){
        return x;
    }
    return -1;
    }
};