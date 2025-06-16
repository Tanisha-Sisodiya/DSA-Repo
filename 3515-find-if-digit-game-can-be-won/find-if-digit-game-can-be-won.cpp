class Solution {
public:
    bool canAliceWin(vector<int>& nums) {
        int sumOneDigit = 0;
        int sumTwoDigit = 0;
        for(int i = 0; i<nums.size(); i++){
            int digits = 0;
            int x = nums[i];
            while(x>0){
                digits++;
                x /= 10;
            }
            
            if(digits == 1){
             sumOneDigit += nums[i];
            }
            if(digits == 2){
             sumTwoDigit += nums[i];
            }
        }
        if(sumOneDigit > sumTwoDigit || sumTwoDigit > sumOneDigit){
            return true;
        }
        return false;
    }
};