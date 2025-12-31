class Solution {
public:
    int row, col;
    vector<vector<int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};

    bool canCross(int day, vector<vector<int>>& cells) {
        vector<vector<int>> grid(row, vector<int>(col, 0));

        for (int i = 0; i < day; i++) {
            grid[cells[i][0] - 1][cells[i][1] - 1] = 1;
        }

        queue<pair<int,int>> q;
        vector<vector<int>> vis(row, vector<int>(col, 0));

        for (int j = 0; j < col; j++) {
            if (grid[0][j] == 0) {
                q.push({0, j});
                vis[0][j] = 1;
            }
        }

        while (!q.empty()) {
            auto [x, y] = q.front(); q.pop();
            if (x == row - 1) return true;

            for (auto &d : dirs) {
                int nx = x + d[0], ny = y + d[1];
                if (nx >= 0 && ny >= 0 && nx < row && ny < col &&
                    !vis[nx][ny] && grid[nx][ny] == 0) {
                    vis[nx][ny] = 1;
                    q.push({nx, ny});
                }
            }
        }
        return false;
    }

    int latestDayToCross(int r, int c, vector<vector<int>>& cells) {
        row = r; col = c;
        int lo = 0, hi = cells.size(), ans = 0;

        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (canCross(mid, cells)) {
                ans = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        return ans;
    }
};
