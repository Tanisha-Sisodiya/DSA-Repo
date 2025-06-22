class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
    vector<int> pos(2, -1);
    int left = 0;
    int right = nums.size()-1;
    while(left<=right){
        if(nums[left]==target){
            pos[0]= left;
            break;
        }
        left++;
    }
    while(right>=left){
        if(nums[right]== target){
            pos[1] = right;
            break;
        }
        right--;
    }
      return pos;

    }
};