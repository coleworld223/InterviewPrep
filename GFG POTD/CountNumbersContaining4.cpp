/*
    Solution1:
    iterate over x : 1 <= x <= n, and find in logn (count of digits <= log n) if x contains '4'
    T.C : O (nlogn)
    S.C : O (1)
    
    Solution2:
    Use digit DP
    DP[idx][can_take_any][has_four_occured] = count of ways we can put digits from idx till end 
                                              where (can_take_any == 1 -> we can take any digits 
                                                     can_take_any == 0 -> we can take smaller digits)
    
    T.C. -> O ((cnt (n)) * 2 * 2 * 10) which is considerably less
    S.C -> O (cnt (n) * 2 * 2), where cnt (n) = no. of digits in n
    
    Solution1 is very intuitive and simple to implement
    Solution2 is implemented below
    
    Note : I've taken modulo here because for large n, ans will not fit in (32 or 64 bit datatype)
           Although here n <= 1e5 -> ans <= 1e5 -> so it doesnt make any difference
*/


const int mod = 1e9 + 7;
using ll = long long;
class Solution {
  public:
    int countNumberswith4(int n) {
        ll dp[101][2][2];
        
        auto reset = [&] () {
            for (int i = 0; i <= n; i += 1) {
                for (int j = 0; j < 2; j += 1) {
                    for (int k = 0; k < 2; k += 1) {
                        dp[i][j][k] = -1;
                    }
                }
            }
        };
        
        function <ll (ll, ll, ll, string&)> F = [&] (ll idx, ll can_take_any, ll four_occured, string&s) {
            ll sz = s.size();
            if (idx >= sz) {
                if (four_occured) return 1ll;
                return 0ll;
            }
            if (dp[idx][can_take_any][four_occured] != -1) return dp[idx][can_take_any][four_occured];
            ll res = 0;
            if (can_take_any) {
                for (ll dig = 0; dig <= 9; dig += 1) {
                    res += F (idx + 1, 1, (ll) (four_occured | (dig == 4)), s);
                    res %= mod;
                }
            }
            else {
                ll mx = (s[idx] - '0');
                for (ll dig = 0; dig <= mx; dig += 1) {
                    res += F (idx + 1, (dig < mx),(ll) (four_occured | (dig == 4)), s);
                    res %= mod;
                }
            }
            return dp[idx][can_take_any][four_occured] = res;
        };
        
        string s = to_string(n);
        reset ();
        ll res = F (0, 0, 0, s);
        return res;
    }
};