class Solution {
public:
    int removeDuplicates(vector<int>&nums) {
        int j = 0;
        for(int i = 0; i < (nums.size()-1); i++){
            int currentElement = nums[i];
            int nextElement = nums[i+1];
            if(currentElement == nextElement){
                continue;
            } else {
            nums[j] = nums[i];
            j++;
            nums[j] = nums[i+1];}
        }
        
        return j+1;
    }
};