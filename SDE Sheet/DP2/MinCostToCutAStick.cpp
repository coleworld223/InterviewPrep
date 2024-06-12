/*
    hints:
    1. think of a 2d state
    2. state hint dp[l][r] = min cost to perform all cuts from indices l to r
*/

/*
    solution:
    dp[l][r] = min cost to do all cuts from index l to r
    dp[l][r] = min (dp[l][x], dp[x][r]) + (cuts[r] - cuts[l]) where l < x < r

    obs:
    for most range dp problems, like (dp[l][r] is calculated from some smaller subarray of [l, r])
    we can calculate dp in order of increasing length
*/

class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort (cuts.begin(), cuts.end());
        int sz = cuts.size();
        vector <vector <int>> dp (sz, vector <int> (sz, (int) 2e9));
        for (int i = 0; i + 1 < sz; i += 1) {
            dp[i][i + 1] = 0;
        }

        for (int len = 3; len <= sz; len += 1) {
            for (int i = 0; i + len - 1 < sz; i += 1) {
                int j = i + len - 1;
                for (int k = i + 1; k < j; k += 1) {
                    dp[i][j] = min (dp[i][j], dp[i][k] + dp[k][j] + (cuts[j] - cuts[i]));
                }
            }
        }
        return dp[0][sz - 1];
    }
};