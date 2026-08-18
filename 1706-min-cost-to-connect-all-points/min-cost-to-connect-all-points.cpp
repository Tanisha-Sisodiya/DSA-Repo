class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<vector<pair<int, int>>> adj(n);
        for(int i = 0; i<n; i++){
            for(int j = i+1; j<n; j++){
                int u = i;
                int v = j;
                int wt = abs((points[i][0]-points[j][0])) + abs((points[i][1]-points[j][1]));
                adj[u].push_back({v, wt});
                adj[v].push_back({u, wt});
            }
        }
        vector<bool> inMST(n, false);
        int ans = 0;
        priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int, int>>>pq;
        pq.push({0, 0});

        while(!pq.empty()){
            int wt = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if(inMST[node] == true){
                continue;
            }

            inMST[node] = true;
            ans += wt;

            for(auto &it: adj[node]){
                int neigh = it.first;
                int wtneigh = it.second;
                if(!inMST[neigh]){
                    pq.push({wtneigh, neigh});
                }
            }
        }

        return ans;
        
    }
};