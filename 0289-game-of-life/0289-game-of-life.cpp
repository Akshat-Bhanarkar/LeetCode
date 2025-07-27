class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int r = board.size();
        int c = board[0].size();
        vector<vector<int>> dir = {{0, 1},   {0, -1}, {1, 0},  {-1, 0},
                                   {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                int count = 0;

                for (auto d : dir) {
                    int x = i + d[0];
                    int y = j + d[1];

                    if(x >= 0 && y >= 0 && x < r && y < c && (board[x][y] == 1 || board[x][y] == 2)){
                        count++;
                    }
                }

                if (board[i][j] == 1 && (count < 2 || count > 3)) {
                    board[i][j] = 2; // alive to dead
                }

                else if (board[i][j] == 0 && count == 3) {
                    board[i][j] = 3; // dead to alive
                }
            }
        }

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (board[i][j] == 2)
                    board[i][j] = 0;
                else if (board[i][j] == 3)
                    board[i][j] = 1;
            }
        }
    }
};