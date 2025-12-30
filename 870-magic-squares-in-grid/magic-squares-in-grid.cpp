class Solution {
public:
    bool isMagic(vector<vector<int>>& g, int r, int c) {
        if (g[r+1][c+1] != 5) return false;

        vector<int> freq(10, 0);
        for (int i = r; i < r + 3; i++) {
            for (int j = c; j < c + 3; j++) {
                int x = g[i][j];
                if (x < 1 || x > 9 || freq[x]++) return false;
            }
        }

        int s = g[r][c] + g[r][c+1] + g[r][c+2];

        return
            g[r+1][c] + g[r+1][c+1] + g[r+1][c+2] == s &&
            g[r+2][c] + g[r+2][c+1] + g[r+2][c+2] == s &&

            g[r][c] + g[r+1][c] + g[r+2][c] == s &&
            g[r][c+1] + g[r+1][c+1] + g[r+2][c+1] == s &&
            g[r][c+2] + g[r+1][c+2] + g[r+2][c+2] == s &&

            g[r][c] + g[r+1][c+1] + g[r+2][c+2] == s &&
            g[r][c+2] + g[r+1][c+1] + g[r+2][c] == s;
    }

    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int r = grid.size(), c = grid[0].size();
        int ans = 0;

        for (int i = 0; i + 2 < r; i++)
            for (int j = 0; j + 2 < c; j++)
                if (isMagic(grid, i, j))
                    ans++;

        return ans;
    }
};
