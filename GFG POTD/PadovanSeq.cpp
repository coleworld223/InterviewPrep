/*
    Hints:
    This is a simple DP problem just testing the basic fundamentals
*/

/*
    Solution:
    state : dp[i] = ith pavodan number
    transition : dp[i] = dp[i - 2] + dp[i - 3]
    
    T.C -> O(n)
    S.C -> O(n) -> O(1) (space optimisation)
*/

const int mod = 1e9 + 7;

class Solution
{
    public:
    int padovanSequence(int n) {
        vector <int> dp (4);
        dp[0] = dp[1] = dp[2] = 1;
        for (int i = 3; i <= n; i += 1) {
            dp[3] = (dp[0] + dp[1]) % mod;
            for (int j = 0; j < 3; j += 1) {
                swap (dp[j], dp[j + 1]);
            }
        }
        return dp[2];
    }
    
};