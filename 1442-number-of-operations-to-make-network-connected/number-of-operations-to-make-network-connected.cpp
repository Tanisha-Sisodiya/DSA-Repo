class Solution {
public:
    int find(int x, vector<int>& parent){
        if(x == parent[x]){
            return parent[x];
        }
        return parent[x] = find(parent[x], parent);
    }
    void Union(int x, int y, vector<int>& parent, vector<int>& rank){
        int parent_x = parent[x];
        int parent_y = parent[y];

        if(parent_x == parent_y) return;
        if(rank[parent_x] >= rank[parent_y]){
            parent[parent_y] = parent_x;
            rank[parent_x]++;

        } else {
            parent[parent_x] = parent_y;
            rank[parent_y]++;
        }

    }

    int makeConnected(int n, vector<vector<int>>& con) {
        int m = con.size();
        if(m < n-1){
            return -1;
        }
        vector<int> parent(n);
        vector<int> rank(n, 0);
        for(int i = 0; i<n; i++){
            parent[i] = i;
        }
        int connections = n-1;
        for(int i = 0; i< m; i++){
            int x = con[i][0];
            int y = con[i][1];
            if(find(x, parent) != find(y, parent)){
                Union(x, y, parent, rank);
                connections--;
            } else {

            }
        }
        return connections;
    }
};