/*
    hints:
    1. find some state
    2. idx, sum, ?
*/

/*
    dp[idx][sum] = can we make a sum equal to 'sum' till index idx
    dp[idx][sum] = dp[idx - 1][sum] | dp[idx - 1][sum - nums[idx]]

    obs : 
    space can be optimised since 
    1. only prev idx is being used
    2. always a smaller sum (sum - nums[idx]) is used for current state 'sum' calculation
    
*/

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        vector <int> dp (20001);
        dp[0] = 1;
        int tot = 0;
        for (int i = 0; i < n; i += 1) {
            tot += nums[i];
            for (int sum = 20000; sum >= 0; sum--) {
                if (sum - nums[i] >= 0) {
                    dp[sum] = max (dp[sum], dp[sum - nums[i]]);
                }
            }
        }
        if (tot % 2 != 0) return 0;
        return dp[tot / 2];
    }
};