class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size();
        int left = 0;
        int right = n-1;
        while(right>left){
            if(arr[right]> arr[left]){ 
                left++;}
            else if(arr[right]< arr[left]) {
                right--;}
            else { 
                right--; left++;}
        }
        return left;
    }
};