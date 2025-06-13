class Solution {
public:
    int maxArea(vector<int>& height) {
       int left = 0;
       int right = height.size()- 1;
       long long area = 0;

       while(left < right){
             long long minHeight = min(height[left], height[right]);
            int width = right - left;
            long long currentArea = 1LL * minHeight * width; 
            area = max(area, currentArea);
       if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
       }
       return area;
    }
};