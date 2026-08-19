class Solution {
public:

    bool isSafe(vector<vector<char>>& board, int row, int col, int no) {

        
        for (int i = 0; i < 9; i++) {
            if (board[row][i] == no + '0') {
                return false;
            }
        }

        
        for (int i = 0; i < 9; i++) {
            if (board[i][col] == no + '0') {
                return false;
            }
        }

        
        int startRow = row - row % 3;
        int startCol = col - col % 3;

       
        for (int i = startRow; i < startRow + 3; i++) {
            for (int j = startCol; j < startCol + 3; j++) {
                if (board[i][j] == no + '0') {
                    return false;
                }
            }
        }

        return true;
    }

    bool help(vector<vector<char>>& board, int row, int col) {

        
        if (row == 9) {
            return true;
        }

        
        if (col == 9) {
            return help(board, row + 1, 0);
        }

        
        if (board[row][col] != '.') {
            return help(board, row, col + 1);
        }

        
        for (int no = 1; no <= 9; no++) {

            if (isSafe(board, row, col, no)) {

                
                board[row][col] = no + '0';

                
                if (help(board, row, col + 1)) {
                    return true;
                }

                
                board[row][col] = '.';
            }
        }

        
        return false;
    }

    void solveSudoku(vector<vector<char>>& board) {
        help(board, 0, 0);
    }
};