class Solution {
public:
    int numberOfPermutations(int n, vector<vector<int>>& r) {
        using ll = long long;
        vector <vector <ll>> dp (n, vector <ll> (401));
        vector <int> eve (n, -1);
        for (int i = 0; i < r.size(); i += 1) {
            eve[r[i][0]] = r[i][1];
        }
        int mod = 1e9 + 7;
        dp[0][0] = 1;
        for (int i = 1; i < n; i += 1) {
            vector <ll> pre (401);
            for (ll j = 0; j <= 400; j += 1) {
                pre[j] = dp[i - 1][j];
                if (j) pre[j] += pre[j - 1];
                pre[j] %= mod;
            }
            if (eve[i] == -1) {
                for (ll j = 0; j <= 400; j += 1) {
                    ll l = max (0ll, j - i);
                    dp[i][j] = pre[j] - (l ? pre[l - 1] : 0);
                    dp[i][j] %= mod;
                    dp[i][j] += mod;
                    dp[i][j] %= mod;
                }
            }
            else {
                ll x = eve[i];
                ll l = max (0ll, x - i);
                dp[i][x] = pre[x] - (l ? pre[l - 1] : 0);
                dp[i][x] %= mod;
                dp[i][x] += mod;
                dp[i][x] %= mod;
            }
        }
        return dp[n - 1][eve[n - 1]];
    }
};