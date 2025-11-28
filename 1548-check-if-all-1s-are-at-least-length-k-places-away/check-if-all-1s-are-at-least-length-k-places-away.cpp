class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int s = -1;
        for(int i = 0; i< nums.size(); i++){
            if(nums[i] == 1){
                if((i - s - 1) < k && s!= -1) return false;
                s = i;
            }
            
        }
        return true;
    }
};