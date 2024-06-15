/*
    Hints : 
    1. Dyanamic Progamming
    2. states : dp[x][y][len] = count of sequences starting from (x, y) and of lenght len

*/

/*
    Solution : 
    dp[x][y][len] = sum of dp[nx][ny][len - 1], where (nx, ny) should be (x, y) or adjacent to (x, y)
    Space optimisation since only prev len (len - 1) values are required for current state evalutation
    
    T.C. -> O (n)
    S.C -> O (n)

*/


using ll = long long;
class Solution {
  public:
    long long getCount(int n) {
        vector <vector <ll>> dp (4, vector <ll> (3, 1));
        dp[3][0] = dp[3][2] = 0;
        for (ll p = 2; p <= n; p += 1) {
            vector <vector <ll>> ndp = dp;
            for (ll x = 0; x < 4; x += 1) {
                for (ll y = 0; y < 3; y += 1) if (dp[x][y] != 0) {
                    for (ll dx = -1; dx <= 1; dx += 1) {
                        for (ll dy = -1; dy <= 1; dy += 1) if (abs (dx) + abs (dy) == 1) {
                            ll nx = x + dx, ny = y + dy;
                            if (nx >= 0 && nx < 4 && ny >= 0 && ny < 3) {
                                ndp[x][y] += dp[nx][ny];
                            }
                        }
                    }
                }
            }
            dp = ndp;
        }
        
        ll ans = 0;
        
        for (ll x = 0; x < 4; x += 1) {
            for (ll y = 0; y < 3; y += 1) {
                ans += dp[x][y];
            }
        }
        return ans;
    }
};