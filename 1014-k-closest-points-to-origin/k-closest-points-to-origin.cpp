class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int n = points.size();
        vector<vector<int>> dist(n, vector<int>(2));
        vector<vector<int>> ans;
        for(int i = 0; i<n; i++){
            int x = points[i][0]*points[i][0];
            int y = points[i][1]*points[i][1];
            dist[i][0] = i;
            dist[i][1] = x+y;
        }
        priority_queue<pair<int, int>, vector<pair<int,int>>,
            greater<pair<int,int>>> pq;
        for(auto it : dist){
            pq.push({it[1], it[0]});
        }
        while(k>0){
            ans.push_back(points[pq.top().second]);
            pq.pop();
            k--;
        }
        return ans;
    }
};