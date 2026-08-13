//Dikshtra Algo
class Solution {
public:
    typedef pair<int, pair<int, int>> P;
    vector<vector<int>> dirs {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
    
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> result(n, vector<int>(m, INT_MAX));
        priority_queue<P, vector<P>, greater<P>>pq;

        result[0][0] = 0;
        pq.push({0, {0,0}});

        while(!pq.empty()){
            int diff = pq.top().first;
            auto coord = pq.top().second;
            int x =  coord.first;
            int y = coord.second;
            pq.pop();

            if(x == n-1 && y== m-1){
                return diff;
            }
            for(auto &dir : dirs){
                int x_ = x + dir[0];
                int y_ = y + dir[1];
            
            if(x_ >= 0 && y_ >= 0 && x_ < n && y_ < m ){
                int absDiff = abs(heights[x][y] - heights[x_][y_]);
                int maxDiff = max(diff, absDiff);
                if(maxDiff < result[x_][y_]){
                    result[x_][y_] = maxDiff;
                    pq.push({maxDiff, {x_, y_}});
                }
            }
            }
        }
        return result[n-1][n-1];
    }
};