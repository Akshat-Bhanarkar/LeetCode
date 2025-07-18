class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        int row = 0, col = cols - 1; // start at top-right

        while (row < rows && col >= 0) {
            int current = matrix[row][col];
            if (current == target) return true; // found
            else if (target < current) col--;   // move left
            else row++;                         // move down
        }
        return false;    }
};