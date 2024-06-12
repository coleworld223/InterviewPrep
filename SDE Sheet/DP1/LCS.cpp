/*
   hints:
   1. What states can help, What information is sufficient?
*/

/*
    solution:
    say dp[x][y] = (max LCS we can obtain if we take first x ele from t1, and first y ele from t2)

                   dp[x][y] can be calculated from dp[x - 1][y], dp[x][y - 1], dp[x - 1][y - 1]
                   how ?

    obs : if we traverse dp table like a Grid (from (0, 0) -> (n - 1, m - 1)) 
          every previous state will be calculated before the current state

*/

class Solution {
public:
    int longestCommonSubsequence(string t1, string t2) {
        int n = t1.size(), m = t2.size();
        vector <vector <int>> dp (n + 1, vector <int> (m + 1));
        dp[0][0] = 0;
        for (int i = 1; i <= n; i += 1) {
            for (int j = 1; j <= m; j += 1) {
                dp[i][j] = max ({dp[i][j], dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1] + (t1[i - 1] == t2[j - 1])});
            }
        }
        return dp[n][m];
    }
};