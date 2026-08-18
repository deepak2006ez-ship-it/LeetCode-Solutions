class Solution {
public:

    bool isSafe(vector<string>& board, int row, int col) {
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < board[i].size(); j++) {

                if (board[i][j] == 'Q') {
                    if (j == col) {
                        return false;
                    }
                    if (abs(row - i) == abs(col - j)) {
                        return false;
                    }
                }
            }
        }

        return true;
    }

    void solveRow(vector<string>& board,
                  int row,
                  vector<vector<string>>& ans) {

        if (row == board.size()) {
            ans.push_back(board);
            return;
        }

        for (int col = 0; col < board[row].size(); col++) {

            if (isSafe(board, row, col)) {

  
                board[row][col] = 'Q';

                
                solveRow(board, row + 1, ans);

                
                board[row][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {

        vector<vector<string>> ans;

        
        vector<string> board(n, string(n, '.'));

       
        solveRow(board, 0, ans);

        return ans;
    }
};