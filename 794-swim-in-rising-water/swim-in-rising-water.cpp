class Solution {
public:
    bool isValid(int x, int y, int n) {
        if (x >= 0 && y >= 0 && x < n && y < n) {
            return true;
        }
        return false;
    }

    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();

        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>,
        greater<tuple<int, int, int>>>
        pq;

        vector<vector<bool>> visited(n, vector<bool>(n, false));

        pq.push({grid[0][0], 0, 0});

        int dr[4] = {-1, 0, 1, 0};
        int dc[4] = {0, -1, 0, 1};

        while (!pq.empty()) {

            auto [time, r, c] = pq.top();
            pq.pop();

            if (visited[r][c])
                continue;

            visited[r][c] = true;

            if (r == n - 1 && c == n - 1)
                return time;

            for (int k = 0; k < 4; k++) {

                int nr = r + dr[k];
                int nc = c + dc[k];

                if (isValid(nr, nc, n) && !visited[nr][nc]) {

                    int newTime = max(time, grid[nr][nc]);

                    pq.push({newTime, nr, nc});
                }
            }
        }

        return -1;
    }
};