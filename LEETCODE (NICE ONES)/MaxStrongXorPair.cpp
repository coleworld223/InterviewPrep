/*
    

*/

using ll = long long;

const int sz = 1e5 + 5;
const int bits = 31;

ll t[sz * bits][2];
ll cnt[sz * bits];
ll _ = 1;

void put (ll x) {
    ll node = 0;
    for (ll bit = bits - 1; bit >= 0; bit -= 1) {
        ll bt = (x >> bit & 1);
        if (t[node][bt] == 0) t[node][bt] = _++;
        node = t[node][bt];
        cnt[node] += 1;
    }
}

void rem (ll x) {
    ll node = 0;
    for (ll bit = bits - 1; bit >= 0; bit -= 1) {
        ll bt = (x >> bit & 1);
        node = t[node][bt];
        cnt[node]--;
    }
}

ll maxXor (ll x) {
    ll res = 0;
    ll node = 0;
    for (ll bit = bits - 1; bit >= 0; bit -= 1) {
        ll bt = (x >> bit & 1);
        if (t[node][1 - bt] != 0 && cnt[t[node][1 - bt]]) {
            res |= (1ll << bit);
            node = t[node][1 - bt];
        }
        else {
            node = t[node][bt];
        }
    }
    return res;
}

ll minXor (ll x) {
    ll res = 0;
    ll node = 0;
    for (ll bit = bits - 1; bit >= 0; bit -= 1) {
        ll bt = (x >> bit & 1);
        if (t[node][bt] != 0 && cnt[t[node][bt]]) {
            node = t[node][bt];
        }
        else {
            res |= (1ll << bit);
            node = t[node][1 - bt];
        }
    }
    return res;
}

class Solution {
public:
    int maximumStrongPairXor(vector<int>& nums) {
        ll n = nums.size();
        sort (nums.begin(), nums.end());
        ll ans = 0;
        auto clear = [&] (ll j) {
            while (j < n) rem (nums[j++]);
        };

        for (ll i = 0, j = 0; i < n; i += 1) {
            put (nums[i]);
            while (nums[i] - nums[j] > nums[j]) {
                rem (nums[j++]);
            }
            ans = max (ans, maxXor (nums[i]));
            if (i == n - 1) clear(j);
        }
        return ans;
    }
};