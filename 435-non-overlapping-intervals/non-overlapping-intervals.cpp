class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end(),
     [](const vector<int>& a, const vector<int>& b) {
         return a[1] < b[1];
     });

        int x = 0;
        int i = 1;
        int count = 0;
        while(i<n){
            if( intervals[x][1]<=intervals[i][0]){
                if(i-x > 1){
                    x+= i-x;
                    i++;
                } else {
                x++;
                i++;
                }
            } else {
                i++;
                count++;
            }
        }
        return count;
    }
};