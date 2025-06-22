class Solution {
public:
    int search(vector<int>& nums, int target) {
        int k = 0;
        int n = nums.size();
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] > nums[i + 1]) {
                k = i + 1;
                break;
            }
        }

    
    int left = 0;
    int right = n -1;
    while(left <= right){
    int mid = left +(right-left)/2;
    int realmid = (mid + k)%n;
    if(nums[realmid]==target){
            return realmid;
        }
    if(nums[realmid]>target){
            right = mid-1;
        }
    else{
            left = mid +1;
        }
    }
    return -1;
    }
};