/*
   hints : 
   1. think of some state, find out if this state can be calculated using some other state
*/

/*
    soltuion:
    dp[i][j] = (max path sum ending at (i, j))
    dp[i][j] = max (dp[i - 1][j], dp[i][j - 1]) + grid[i][j]
*/

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();

        vector <vector <int>> dp (n + 1, vector <int> (m + 1, 1e9));
        dp[0][0] = grid[0][0];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i - 1 >= 0) dp[i][j] = min (dp[i][j], dp[i - 1][j] + grid[i][j]);
                if (j - 1 >= 0) dp[i][j] = min (dp[i][j], dp[i][j - 1] + grid[i][j]);
            }
        }
        return dp[n - 1][m - 1];
    }
};