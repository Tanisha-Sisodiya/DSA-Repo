class Solution {
public:
    void dijkstra(int n, vector<vector<pair<int, int>>>&adj, int S, vector<int>& result){
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>>pq;
        pq.push({0,S});
        fill(result.begin(), result.end(), INT_MAX);
        result[S] = 0;
        while(!pq.empty()){
            int d = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for(auto& p: adj[node]){
                int adjNode = p.first;
                int dist = p.second;
                if(d + dist < result[adjNode]){
                    result[adjNode] = d + dist;
                    pq.push({d+dist, adjNode});
                }
            }
        }

    }
    
    int findTheCity(int n, vector<vector<int>>& edges, int dT) { 
        vector<vector<pair<int, int>>>adj(n);
        for(auto it: edges){
            int u = it[0];
            int v = it[1];
            int d = it[2];
            adj[u].push_back({v, d});
            adj[v].push_back({u, d});
        }
        vector<vector<int>> SPM(n, vector<int>(n, INT_MAX));
        for(int i = 0; i<n; i++){
            SPM[i][i] = 0;
        }

        for(int i = 0; i<n ; i++){
            dijkstra(n, adj, i, SPM[i]);
        }
        int leastReachCount = INT_MAX;
        int resultCity = -1;

        for(int i = 0; i<n; i++){
            int countReach = 0;
            for(int j = 0; j<n; j++){
                if(i!=j && SPM[i][j] <= dT){
                    countReach++;
                }
            }
            if(countReach <= leastReachCount){
                leastReachCount = countReach;
                resultCity = i;
            }
        }

        return resultCity;
    }
};