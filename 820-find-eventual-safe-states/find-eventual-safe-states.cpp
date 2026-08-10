class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> adj(n);
        vector<int>indegree(n);
        for(int u = 0; u<n; u++){
            for(int v: graph[u]){
                adj[v].push_back(u);
                indegree[u]++;
            }
        }
        queue<int> q;
        for(int i = 0; i<n; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        vector<int> isSafe(n, false);
        while(!q.empty()){
            int u = q.front();
            q.pop();
            isSafe[u] = true;

            for(int v: adj[u]){
                indegree[v]--;

                if(indegree[v] == 0){
                    q.push(v);
                }
            }
        }
        vector<int> Safe;
        for(int i = 0; i<n; i++){
            if(isSafe[i]){
                Safe.push_back(i);
            }
        }
        return Safe;
    }
};