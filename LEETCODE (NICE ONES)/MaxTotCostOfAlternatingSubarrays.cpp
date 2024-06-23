class Solution {
public:
    long long maximumTotalCost(vector<int>& nums) {
        using ll = long long;
        ll inf = 1e18;
        ll n = nums.size();
        vector <ll> dp (2, -inf);
        dp[1] = nums[0];
        for (ll i = 1; i < n; i ++) {
            vector <ll> dp1 (2, -inf);
            if (dp[0] != -inf) {
                dp1[1] = max (dp1[1], dp[0] + nums[i]);
            }
            if (dp[1] != -inf) {
                dp1[1] = max (dp1[1], dp[1] + nums[i]);
                dp1[0] = max (dp1[0], dp[1] - nums[i]);
            }
            dp = dp1;
        }
        ll ans = max (dp[0], dp[1]);
        return ans;
    }
};