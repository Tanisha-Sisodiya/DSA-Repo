class Solution {
public:
    int signFunc(int x){
    if(x== 1){
        return 1;
    }
        return -1;
    
    }

    int arraySign(vector<int>& nums) {
        int product = 1;
        for(int i = 0;i< nums.size(); i++){
            if(nums[i]>0){
                nums[i]= 1;
            }
            if(nums[i]<0){
                nums[i] = -1;
            }
            if(nums[i]== 0){
                return 0;
            }
            product *= nums[i];
        }
        return signFunc(product);
    }
};