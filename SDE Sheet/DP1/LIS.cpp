/*
   hints:
   1. DP
   2. what states can we try -> index, element?
*/

/*
   solution:
   state : dp[x] = (till now, what's the LIS ending with element x)
   transition : dp[x] = max (1, dp[y] + 1) , where y < x
                Range min query can be used

    Range min query {
        Any (point update range min query) date structure can be use
        Here I've used Dyanamic STs since it gives a lot of flexibility in terms of what range of numbers it can handle 
        Dyanamic Segment trees (can find it on CP Algorithms)
    }

*/

using ll = long long;
ll def_value = 0;

struct Node {
    Node* lft = NULL;
    Node* rht = NULL;
    ll l, r, val;

    Node (ll l1, ll r1) {
        l = l1;
        r = r1;
        val = def_value;
    }

    void extend () {
        if (!lft && l + 1 <= r) {
            ll mid = (l + r) >> 1;
            lft = new Node (l, mid);
            rht = new Node (mid + 1, r);
        }
    }

    void put (ll p, ll x) {
        if (l == r) {
            val = x;
            return;
        }
        extend ();
        ll mid = (l + r) >> 1;
        if (p <= mid) lft -> put (p, x);
        else rht -> put (p, x);
        val = max (lft -> val, rht -> val);
    }

    ll qry (ll ql, ll qr) {
        if (l >= ql && r <= qr) return val;
        extend();
        ll res = 0;
        ll mid = (l + r) >> 1;
        if (ql <= mid) res = max (res, lft -> qry (ql, qr));
        if (qr >= mid + 1) res = max (res, rht -> qry (ql, qr));
        return res;
    }
};


class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        ll n = nums.size();
        Node* root = new Node (0, 1e18);
        ll ofset = 10005; // since nums[i] can be smaller than 0

        for (int i = 0; i < n; i += 1) {
            ll mx = 1;
            mx = max (mx, root -> qry (0, nums[i] - 1 + ofset) + 1);
            root -> put (nums[i] + ofset, mx);
        }

        int ans = root -> qry (0, 1e18);
        return ans;
    }
};