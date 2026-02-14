class Solution {
public:

    void merge(vector<int>&nums, int s, int m , int e){
        vector<int> temp;
        int i = s;
        int j = m+1;
        while(i <= m && j<= e){
            if(nums[i] <= nums[j]){
                temp.push_back(nums[i]);
                i++;         
            } else {
                temp.push_back(nums[j]);
                j++;
            }
        }
        while(i <= m){
            temp.push_back(nums[i]);
            i++;  
        }
        while(j <= e){
             temp.push_back(nums[j]);
            j++;
        }
        for(int i = 0; i<temp.size(); i++){
            nums[i+s] = temp[i];
        }

    }
    void mergeSort(vector<int>& nums, int s, int e){
        int m = s + (e-s)/2;
        if(s<e){
        mergeSort(nums, s, m);
        mergeSort(nums, m+1,e);
        merge(nums, s, m, e);
        }
    }

    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        int s = 0;
        int e = n - 1;
        mergeSort(nums, s, e);  
        return nums;
    }
};