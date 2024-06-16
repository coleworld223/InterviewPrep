/*
    PS : 
    Given a string (say s), find the length of the smallest string t
    such that s can be formed by concatinating the anargams of t

    Note : 
    Anargan of a string is rearrangement of the string, such that count of each char remains same
    for e.g. abac and acab are anargams

*/

/*
    Solution : 
    Check for all lengths -> This will require O (n * logn * 26) time

    By using string hashing we can do it in O(n * logn)

    Both the implementaitons are below

*/


// Hashing 

using ll = long long;
const ll p = 31;
const ll mod1 = 1e9 + 7, mod2 = 999999937;

ll binpow (ll a, ll b, ll mod) {
    ll res = 1, mul = a;
    for (ll bit = 0; bit < 31; bit += 1) {
        if (b >> bit & 1) {
            res *= mul;
            res %= mod;
        }
        mul *= mul;
        mul %= mod;
    }
    return res;
}

ll inverse (ll x, ll mod) {
    return binpow (x, mod - 2, mod);
}

int solve (string s) {
    ll n = s.size();

    vector <ll> inv1 (n), h1 (n), h2 (n), inv2 (n);
    h1[0] = (s[0] + p) % mod1;
    inv1[0] = inverse (h1[0], mod1);
    h2[0] = (s[0] + p) % mod2;
    inv2[0] = inverse (h2[0], mod2);

    for (ll i = 1; i < n; i += 1) {
        h1[i] = ((s[i] + p) * h1[i - 1]) % mod1;
        inv1[i] = inverse(h1[i], mod1);
        h2[i] = ((s[i] + p) * h2[i - 1]) % mod2;
        inv2[i] = inverse (h2[i], mod2);
    }

    auto giv = [&] (ll l, ll r) -> pair <ll, ll> {
        return {(h1[r] * (l ? inv1[l - 1] : 1)) % mod1, (h2[r] * (l ? inv2[l - 1] : 1)) % mod2};
    };

    for (ll len = 1; len <= n; len += 1) if (n % len == 0) {
        auto hash = giv (0, 0 + len - 1);
        bool f = 1;
        for (ll i = 0; i < n; i += len) {
            auto tmp_hash = giv (i, i + len - 1);
            if (tmp_hash != hash) {
                f = 0;
                break; 
            }
        }
        if (f) return len;
    }
    return n;
}



/*******************************************************************************************************************************/

// Normal frequency array comparision
int solve (string s) {
    int n = s.size();
    vector <vector <int>> cnt (n, vector <int> (26));

    auto giv = [&] (int l, int r) -> vector <int> {
        vector <int> res (26);
        for (int i = 0; i < 26; i += 1) {
            res[i] = cnt[r][i] - (l ? cnt[l - 1][i] : 0);
        }
        return res;
    };

    for (int i = 0; i < n; i += 1) {
        cnt[i][s[i] - 'a'] += 1;
        for (int j = 0; j < 26; j += 1) if (i) {
            cnt[i][j] += cnt[i - 1][j];
        }
    }

    for (int len = 1; len <= n; len += 1) {
        if (n % len != 0) continue;
        bool f = 1;
        vector <int> h = giv (0, 0 + len - 1);
        for (int i = 0; i < n; i += len) {
            vector <int> r = giv (i, i + len - 1);
            if (r != h) {
                f = 0;
                break;
            }
        }
        if (f) {
            return len;
        }
    }
    return n;
}