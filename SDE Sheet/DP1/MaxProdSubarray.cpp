/*
    hints
    1. try finding the max prod subarray ending at (say mx[i])
    2. do we need to see the prod of all subarrays ending at i - 1
       to find mx[i]
*/

/*
   solution:
   mx[i] = max (mn[i - 1] * a[i], mx[i - 1] * a[i], a[i])
   why ? 
*/

class Solution {
public:
    using ll = long long;
    ll inf = 1e18;
    bool checkOverflow (ll x, ll y) {
        return ((x == 0 || y == 0) || (abs (x) <= abs (inf / y))); // (x * y) <= inf   <=>   (x <= (inf / y)) 
    }

    void maximize(ll& x, ll y) {
        x = max (x, y);
    }

    void minimize(ll& x, ll y) {
        x = min (x, y);
    }
    int maxProduct(vector<int>& nums) {
        ll n = nums.size();
        ll mx, mn, ans;
        mx = mn = ans = nums[0];

        for (ll i = 1; i < n; i += 1) {
            ll new_mx, new_mn;
            new_mx = new_mn = nums[i];
            if (checkOverflow (mx, nums[i])) {
                maximize (new_mx, nums[i] * mx);
                minimize (new_mn, nums[i] * mx);
            }
            if (checkOverflow (mn, nums[i])) {
                maximize (new_mx, nums[i] * mn);
                minimize (new_mn, nums[i] * mn);
            }
            mx = new_mx;
            mn = new_mn;
            maximize (ans, mx);
        }

        return ans;
    }
};