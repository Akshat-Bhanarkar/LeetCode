class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<int> res;
        res.reserve(m * n);
        for (int d = 0; d < m + n - 1; ++d) {
            int row, col;
            if (d % 2 == 0) {
                row = (d < m) ? d : m - 1;
                col = d - row;
                while (row >= 0 && col < n) res.push_back(mat[row--][col++]);
            } 
            else {
                col = (d < n) ? d : n - 1;
                row = d - col;
                while (col >= 0 && row < m) res.push_back(mat[row++][col--]);
            }
        }
        return res;
    }
};