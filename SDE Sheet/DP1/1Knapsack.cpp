/*
    hints:
	1. What information is sufficient?
	2. Index and wt_used/wt_left
*/

/*
    solution:
    dp[idx][wt] = max value attainable using 'wt' weight till 'idx' index
	transition:
	dp[idx][wt] = max(dp[idx - 1][wt], dp[idx - 1][wt - weights[idx]]);

	obs : 
	1. ans for idx can be calculated from idx - 1 only (we dont need idx - x (x > 1))
	2. dp[idx][wt] = dp[idx - 1][wt - weight[idx]]
	   here weight[idx] >= 0 always, so we can maintain the dp values
	   with one vector of size (W) only (how ?)
*/



int maxProfit(vector<int> &values, vector<int> &weights, int n, int w) {
	vector <int> dp (1001);
	int ans = 0;
	for (int idx = 0; idx < n; idx += 1) {
		for (int wt = w; wt >= 0; wt--) {
			if (wt - weights[idx] >= 0) {
				dp[wt] = max (dp[wt], dp[wt - weights[idx]] + values[idx]);
			}
			ans = max (ans, dp[wt]);
		}
	}
	return ans;
}