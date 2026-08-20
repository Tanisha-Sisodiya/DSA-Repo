class Solution {
public:
    bool isValid(int row, int col, int n){
        if(row < n && col < n && row >= 0 && col >= 0){
            return true;
        }
        return false;
    }
    int find(int x, vector<int>& parent){
        if(x == parent[x]) return parent[x];
        return parent[x] = find(parent[x], parent);
    }
    void Union(int x, int y, vector<int>& parent, vector<int>& size) {
        int parent_x = find(x, parent);
        int parent_y = find(y, parent);

        // Already in the same set
        if(parent_x == parent_y) return;

        // Attach smaller tree to larger tree
        if(size[parent_x] >= size[parent_y]) {
            parent[parent_y] = parent_x;
            size[parent_x] += size[parent_y];
        }
        else {
            parent[parent_x] = parent_y;
            size[parent_y] += size[parent_x];
        }
    }
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        bool x = false;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                if(grid[i][j] == 0){
                    x = true;
                }
            }
        }
        if(x == false) return n*n;

        vector<int> parent(n*n);
        for(int i = 0; i<n*n; i++){
            parent[i] = i;
        }
        vector<int>size(n*n, 1);
        for(int i = 0; i<n ; i++){
            for(int j = 0; j<n; j++){
                if(grid[i][j] == 0) continue;
                int dr[] = {-1, 0, 1, 0};
                int dc[] = {0, -1, 0, 1};
                for(int k = 0; k<4; k++){
                    int newr = i+dr[k];
                    int newc = j+dc[k];
                    if(isValid(newr, newc, n) && grid[newr][newc] == 1){
                        int nodeNo = i*n + j;
                        int adjNodeNo = newr*n + newc;
                        Union(nodeNo, adjNodeNo, parent, size);
                    }
                }
            }
        }
        int mx = 0;
        for(int i = 0; i<n ; i++){
            for(int j = 0; j<n; j++){
                if(grid[i][j] == 1) continue;
                int dr[] = {-1, 0, 1, 0};
                int dc[] = {0, -1, 0, 1};
                set<int>components;
                for(int k = 0; k<4; k++){
                    int newr = i+dr[k];
                    int newc = j+dc[k];
                    if(isValid(newr, newc, n)){
                        if(grid[newr][newc] == 1){
                            components.insert(find(newr*n + newc, parent));
                        }
                    }
                }
                int sizeTotal = 1;
                for(auto it: components){
                     sizeTotal += size[it];
                }
                mx = max(mx, sizeTotal);
            }
        }
        return mx;
    }
};