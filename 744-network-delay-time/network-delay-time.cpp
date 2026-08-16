class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        vector<vector<pair<int, int>>> adj(n + 1);

        for (auto edge : times) {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];

            adj[u].push_back({v, wt});
        }

        vector<int> dist(n + 1, INT_MAX);
        dist[k] = 0;

        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>
        > pq;

        pq.push({0, k});

        while (!pq.empty()) {

            int currTime = pq.top().first;
            int u = pq.top().second;

            pq.pop();

            if (currTime > dist[u])
                continue;

            for (auto neigh : adj[u]) {

                int v = neigh.first;
                int wt = neigh.second;

                if (currTime + wt < dist[v]) {

                    dist[v] = currTime + wt;

                    pq.push({dist[v], v});
                }
            }
        }

        int ans = 0;

        for (int i = 1; i <= n; i++) {

            if (dist[i] == INT_MAX)
                return -1;

            ans = max(ans, dist[i]);
        }

        return ans;
    }
};