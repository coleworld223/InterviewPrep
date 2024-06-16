// https://leetcode.com/contest/weekly-contest-402/problems/peaks-in-array/


/*  Hints :
    1. Any query would not affect the state of more than 3 indices
    2. Range query ds can maintain the sum of states for you
*/

/*
    Solution:
    employ a range sum query (below used is Dyanamic segment tree)
    have tree[idx] = 1 (if peak)
         tree[idx] = 0 (else)

    for update query, update at most 3 indices (i, i - 1, i + 1)
    for ans query, use range sum
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
        val = (lft -> val) + (rht -> val);
    }

    ll qry (ll ql, ll qr) {
        if (l >= ql && r <= qr) return val;
        extend();
        ll res = 0;
        ll mid = (l + r) >> 1;
        if (ql <= mid) res = (res + lft -> qry (ql, qr));
        if (qr >= mid + 1) res = (res + rht -> qry (ql, qr));
        return res;
    }
};

class Solution {
public:
    vector<int> countOfPeaks(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        Node* root = new Node (0, n);
        
        auto chk = [&] (ll i) {
            if (i > 0 && i < n - 1) {
                if (nums[i] > nums[i - 1] && nums[i] > nums[i + 1]) {
                    root -> put (i, 1);
                }
                else {
                    root -> put (i, 0);
                }
            }
        };
        
        for (ll i = 0; i < n; i += 1) {
            chk (i);
        }
        
        vector <int> ans;
        
        for (auto x : queries) {
            int tp = x[0], l = x[1], r = x[2];
            if (tp == 1) {
                int res = root -> qry (l, r) - (root -> qry (l, l)) - (root -> qry (r, r));
                res = max (res, 0);
                ans.push_back(res);
            }
            else {
                nums[l] = r;
                for (int i = max (0, l - 1); i <= min (n - 1, l + 1); i += 1) {
                    chk (i);
                }
            }
        }
        return ans;
    }
};