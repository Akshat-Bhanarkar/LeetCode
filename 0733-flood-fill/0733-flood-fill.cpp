class Solution {
private:
    void dfs(int row, int col, int deltarow[], int deltacol[],
             vector<vector<int>>& image, int orgcolor, int color,
             vector<vector<int>>& ans) {
        ans[row][col] = color;
        int n = image.size(), m = image[0].size();
        for (int i = 0; i < 4; i++) {
            int nrow = row + deltarow[i];
            int ncol = col + deltacol[i];
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                image[nrow][ncol] == orgcolor && ans[nrow][ncol] != color) {
                dfs(nrow, ncol, deltarow, deltacol, image, orgcolor, color,
                    ans);
            }
        }
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int color) {
        vector<vector<int>> ans = image;
        int orgcolor = image[sr][sc];

        if (orgcolor == color)
            return image;

        int deltarow[] = {-1, 0, 1, 0};
        int deltacol[] = {0, 1, 0, -1};

        dfs(sr, sc, deltarow, deltacol, image, orgcolor, color, ans);
        return ans;
    }
};