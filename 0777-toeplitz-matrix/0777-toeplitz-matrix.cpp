class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        // check diagonal row wise
        for (int i = 0, j = 0; j < cols; j++) {
            int cur = matrix[i][j];
            int m = i, n = j;
            while (m < rows && n < cols) {
                if (matrix[m][n] != cur) return false;
                m++;
                n++;
            }
        }

        // check diagonal column wise
        for (int i = 1, j = 0; i < rows; i++) {
            int cur = matrix[i][j];
            int m = i, n = j;
            while (m < rows && n < cols) {
                if (matrix[m][n] != cur) return false;
                m++;
                n++;
            }
        }

        return true;
    }
};