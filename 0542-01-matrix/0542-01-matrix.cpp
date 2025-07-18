class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        queue<pair<int, int>> q;

        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (mat[i][j] == 0)
                    q.push({i, j});
                else
                    mat[i][j] = -1; // mark unvisited 1s

        vector<int> dirs = {0, 1, 0, -1, 0};
        while (!q.empty()) {
            auto [x, y] = q.front(); q.pop();
            for (int d = 0; d < 4; ++d) {
                int nx = x + dirs[d], ny = y + dirs[d + 1];
                if (nx >= 0 && ny >= 0 && nx < m && ny < n && mat[nx][ny] == -1) {
                    mat[nx][ny] = mat[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }
        return mat;
    }
};