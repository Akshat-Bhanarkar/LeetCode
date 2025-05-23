class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int r = grid.size(), c = grid[0].size(), len = 0;
        for(int i = 0; i < r; ++i){
            for(int j = 0; j < c; ++j){
                if(grid[i][j]){
                    len += 4;
                    if(i > 0 && grid[i - 1][j]) len--;
                    if(i < r - 1 && grid[i + 1][j]) len--;
                    if(j > 0 && grid[i][j - 1]) len--;
                    if(j < c - 1 && grid[i][j + 1]) len--;
                }
            }
        }
        return len;
    }
};