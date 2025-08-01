class Solution {
public:
    bool validTicTacToe(vector<string>& board) {
        int countX = 0, countO = 0;
        for (string row : board) {
            for (char cell : row) {
                if (cell == 'X') countX++;
                if (cell == 'O') countO++;
            }
        }
        
        if (countO > countX || countX > countO + 1) return false;
        
        bool xWins = isWinner(board, 'X');
        bool oWins = isWinner(board, 'O');

        if (xWins && oWins) return false;
        if (xWins && countX != countO + 1) return false;
        if (oWins && countX != countO) return false;
        
        return true;
    }
    
    bool isWinner(vector<string>& board, char player) {
        for (int i = 0; i < 3; i++) {
            if (board[i] == string(3, player) || 
                (board[0][i] == player &&
                 board[1][i] == player &&
                 board[2][i] == player)) {
                return true;
            }
        }
        return (board[0][0] == player &&
                board[1][1] == player &&
                board[2][2] == player) ||
               (board[0][2] == player &&
                board[1][1] == player &&
                board[2][0] == player);
    }
};