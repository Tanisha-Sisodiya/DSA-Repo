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
    int removeStones(vector<vector<int>>& s) {
        int n = s.size();
        vector<int> parent(n);
        vector<int> rank (n, 0);
        int ans = 0;
        for(int i = 0; i<n ; i++){
            parent[i] = i;
        }
        for(int i = 0; i<n; i++){
            for(int j = i+1; j<n; j++){
                if(find(i, parent) != find(j, parent)){
                    if(s[i][0] == s[j][0] || s[i][1] == s[j][1]){
                        Union(i, j, parent, rank);
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};