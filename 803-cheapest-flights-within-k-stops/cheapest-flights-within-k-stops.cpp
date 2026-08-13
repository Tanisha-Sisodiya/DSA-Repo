class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<vector<int>>> adj(n);
        vector<int> dist(n, INT_MAX);
        for(int i = 0; i< flights.size() ; i++){
            int u = flights[i][0];
            int v = flights[i][1];
            int cost = flights[i][2];
            adj[u].push_back({v, cost});
        }
        queue<pair<int,int>>q;
        q.push({src, 0});
        dist[src] = 0;
        int steps = 0;

        while(!q.empty() && steps <= k){

            int N = q.size();

            while(N--){
            int u = q.front().first;
            int cost = q.front().second;
            q.pop();
            for(auto V : adj[u]){
                int v = V[0];
                int costV = V[1];
                if(cost + costV < dist[v]){
                    dist[v] = cost + costV;
                    q.push({v,cost + costV});
                }
            }
            }
            steps++;
        }

        return dist[dst] == INT_MAX ? -1 : dist[dst];

    }
};