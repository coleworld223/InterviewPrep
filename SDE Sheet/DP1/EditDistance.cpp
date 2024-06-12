/*
   hints : 
   1. state that can work dp[idx of w1][idx of w2] = min cost to make equal till (idx of w1) and (idx of w2)
*/

/*
    solution:
    using the state as in hints
    transition:
    dp[i][j] = min (dp[i - 1][j] + 1, dp[i][j - 1] + 1, dp[i - 1][j - 1] + (w1[i] != w2[j]))

    see the transitions as:
    dp[i - 1][j] -> inserting a char in w2
    dp[i][j - 1] -> inserting a char in w1
    dp[i - 1][j - 1] + (w1[i] != w2[j]) -> replacing a char in w1 or w2 (always replace such that the concerned 
                                            positions become equal (why ?))
    
    obs : 
    we can cut a lot of conditional statements if we consider the string as 1 based indexed
*/

class Solution {
public:
    int minDistance(string w1, string w2) {
        int n = w1.size(), m = w2.size();
        vector <vector <int>> dp (n + 1, vector <int> (m + 1, (int) 1e9));
        dp[0][0] = 0;
        for (int i = 1; i <= n; i += 1) {
            dp[i][0] = i;
        }
        for (int j = 1; j <= m; j += 1) {
            dp[0][j] = j;
        }

        for (int i = 1; i <= n; i += 1) {
            for (int j = 1; j <= m; j += 1) {
                dp[i][j] = min ({dp[i][j], dp[i - 1][j] + 1, dp[i][j - 1] + 1, dp[i - 1][j - 1] + (w1[i - 1] != w2[j - 1])});
            }
        }
        return dp[n][m];
    }
};