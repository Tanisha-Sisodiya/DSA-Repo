class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int digits = 0;
        int count = 0;
        for(int i = 0; i< nums.size(); i++){
            while(nums[i]>0){
                nums[i] /= 10;
                digits++;
            }
            if(digits%2 == 0){ count++;}
            digits = 0;
        }
        return count;
    }
};