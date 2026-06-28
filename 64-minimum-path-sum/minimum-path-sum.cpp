class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int p = grid[0].size();

        if (n == 0 || p == 0) {
            return 0;
        }

        vector<vector<int>> dp(n, vector<int>(p, 0));


        dp[0][0] = grid[0][0];


        for (int r = 1; r < p; r++) {
            dp[0][r] = dp[0][r - 1] + grid[0][r];
        }

        for (int q = 1; q < n; q++) {
            dp[q][0] = dp[q - 1][0] + grid[q][0];
        }

        for (int q = 1; q < n; q++) {
            for (int r = 1; r < p; r++) {
                dp[q][r] = min(dp[q - 1][r], dp[q][r - 1]) + grid[q][r];
            }
        }

        return dp[n - 1][p - 1];
    }
};