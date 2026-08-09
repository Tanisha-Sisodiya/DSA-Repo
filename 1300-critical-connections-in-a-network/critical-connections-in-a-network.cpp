class Solution {
public:
    int timer = 0;

    void dfs(int u, int par,
             vector<bool>& vis,
             vector<int>& dt,
             vector<int>& low,
             vector<vector<int>>& adj,
             vector<vector<int>>& ans) {

        vis[u] = true;

        dt[u] = low[u] = ++timer;

        for (int v : adj[u]) {

            if (v == par)
                continue;

            if (!vis[v]) {

                dfs(v, u, vis, dt, low, adj, ans);

                // Update low-link value
                low[u] = min(low[u], low[v]);

                // Bridge condition
                if (low[v] > dt[u]) {
                    ans.push_back({u, v});
                }

            } else {

                // Back edge
                low[u] = min(low[u], dt[v]);
            }
        }
    }

    vector<vector<int>> criticalConnections(
        int n,
        vector<vector<int>>& connections
    ) {

        vector<vector<int>> adj(n);

        for (auto& edge : connections) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> vis(n, false);
        vector<int> dt(n, 0);
        vector<int> low(n, 0);

        vector<vector<int>> ans;

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                dfs(i, -1, vis, dt, low, adj, ans);
            }
        }

        return ans;
    }
};