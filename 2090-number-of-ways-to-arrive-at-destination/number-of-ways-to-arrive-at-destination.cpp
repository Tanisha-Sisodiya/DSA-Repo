class Solution {
public:
    

    int countPaths(int n, vector<vector<int>>& roads) {

        const int MOD = 1e9 + 7;
        vector<pair<int, int>> adj[n];
        for(auto it : roads){
           adj[it[0]].push_back({it[1], it[2]});
           adj[it[1]].push_back({it[0], it[2]});
        }
        vector<long long> dist(n, LLONG_MAX);
        vector<int> ways(n, 0);
        dist[0] = 0;
        ways[0] = 1;

        priority_queue<
        pair<long long, int>,
        vector<pair<long long, int>>,
        greater<pair<long long, int>>>pq;

        pq.push({0, 0});

        while(!pq.empty()){
            long long d = pq.top().first;
            int u = pq.top().second;
            pq.pop();

            if (d > dist[u])
                continue;
            for(auto it: adj[u]){
                long long dv = it.second;
                int v = it.first;
                long long newDist = d + dv;
                if(newDist < dist[v]){
                    dist[v] = newDist;
                    pq.push({dist[v], v});
                    ways[v] = ways[u];
                } else if(newDist == dist[v]){
                     ways[v] = (ways[u] + ways[v])%MOD;
                }
                
            }
        }
        
        return ways[n-1];
    }
};