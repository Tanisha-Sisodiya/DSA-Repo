class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        vector<int> indegree (n, 0);
        for(int i = 0; i<prerequisites.size(); i++){
            indegree[prerequisites[i][0]]++;
        }
        vector<vector<int>> adj(n);
        for(int i = 0; i<prerequisites.size(); i++){
            int u = prerequisites[i][1];
            int v = prerequisites[i][0];
            adj[u].push_back(v);
        }
        queue<int>q;
        for(int i = 0; i<indegree.size(); i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        vector<int> result;
        while(!q.empty()){
            int u = q.front();
            q.pop();
            result.push_back(u);
            for(int &v : adj[u]){
                indegree[v]--;
                if(indegree[v] == 0){
                    q.push(v);
                }
            }
        }
        if(result.size() != n){
            return {};
        }
        return result;
    }
};