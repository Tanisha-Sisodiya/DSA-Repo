class Solution {
public:
    int findMin(vector<int>& nums) {
           int n = nums.size();
           int left = 0;
           int right = n-1;
    
           while(left<=right){
           int mid = left + (right-left)/2;
           if(left == right){
            return nums[left];
           }

           
           if(nums[mid]>nums[right]){
            left = mid+1;
           }
           if(nums[mid]<nums[right]){
            right = mid;
           }
           
           }
           return nums[left];
    }
};