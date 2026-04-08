class Solution {
public:
    void solve(int row, int n, vector<string>& board,
               vector<vector<string>>& ans,
               vector<int>& colUsed,
               vector<int>& diag1,
               vector<int>& diag2) {

        // ✅ Base case: all rows filled
        if (row == n) {
            ans.push_back(board);
            return;
        }

        for (int col = 0; col < n; col++) {

            // ✅ Check if safe in O(1)
            if (colUsed[col] == 0 &&
                diag1[row + col] == 0 &&
                diag2[n - 1 + col - row] == 0) {

                // 👉 Place queen
                board[row][col] = 'Q';
                colUsed[col] = 1;
                diag1[row + col] = 1;
                diag2[n - 1 + col - row] = 1;

                // 👉 Go to next row
                solve(row + 1, n, board, ans, colUsed, diag1, diag2);

                // 🔁 Backtrack (UNDO)
                board[row][col] = '.';
                colUsed[col] = 0;
                diag1[row + col] = 0;
                diag2[n - 1 + col - row] = 0;
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;

        vector<string> board(n, string(n, '.'));

        vector<int> colUsed(n, 0);
        vector<int> diag1(2*n - 1, 0);  // row+col
        vector<int> diag2(2*n - 1, 0);  // n-1 + col-row

        solve(0, n, board, ans, colUsed, diag1, diag2);

        return ans;
    }
};