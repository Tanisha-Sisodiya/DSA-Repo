class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> leftMax(n,0);
        vector<int> rightMax(n,0);
        int max = 0;
        leftMax[0] = -1;
        rightMax[n-1] = -1;
        int ans = 0;
        for(int i = 1; i< n; i++){
            if(height[i-1]> max){
                max = height[i-1];
            }
            if(height[i]<max){
                leftMax[i] = max;
            } else {
                leftMax[i] = -1;
            }
        }
        max = 0;
        for(int i = n-2; i>=0; i--){
            if(height[i+1]> max){
                max = height[i+1];
            }
            if(height[i]<max){
                rightMax[i] = max;
            } else {
                rightMax[i] = -1;
            }
        }
        for(int i = 0; i< n; i++){
            ans += (rightMax[i]== -1 || leftMax[i]== -1) ? 0: (min(rightMax[i],leftMax[i]) - height[i]);
        }
        return ans;
    }
};