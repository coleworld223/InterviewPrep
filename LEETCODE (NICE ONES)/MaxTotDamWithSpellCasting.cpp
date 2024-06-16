// https://leetcode.com/contest/weekly-contest-402/problems/maximum-total-damage-with-spell-casting/

/*
    Hints:
    1. if you take x, you cannot take x - 1 and x - 2 (is this condition a sufficient replacement of given condition)
    2. Use dyanamic programming
    3. states dp[x] = taking elements <= x, what's the max damage we can accumulate
*/

/*
    Solution:
    dp[x] = taking elements <= x, what's the max damage we can accumulate
    dp[x] = max (dp[x - 1], dp[x - 3] + cnt[x] * x)

    A possible implementation could be as follows;
*/

class Solution {
public:
    using ll = long long;
    long long maximumTotalDamage(vector<int>& p) {
        map <ll, ll> cnt;
        for (ll x : p) {
            cnt[x] += 1;
        }
        vector <ll> tmp;
        for (auto [x, y] : cnt) {
            tmp.push_back(x);
        }
        ll n = tmp.size();
        vector <ll> dp (n);
        ll ans = 0;
        for (ll i = 0; i < n; i += 1) {
            dp[i] += (cnt[tmp[i]] * tmp[i]);
            for (ll j = i - 1; j >= 0; j--) {
                if (tmp[j] < tmp[i] - 2) {
                    dp[i] += dp[j];
                    break;
                }
            }
            if (i) dp[i] = max (dp[i], dp[i - 1]);
            ans = max (ans, dp[i]);
        }
        return ans;
    }
};