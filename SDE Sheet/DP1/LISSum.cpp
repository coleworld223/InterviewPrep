using ll = long long;

ll def_value = 0;

struct Node {
    Node* lft = NULL;
    Node* rht = NULL;
    ll l, r, val;
    Node (ll l1, ll r1) {
        l = l1, r = r1;
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
            val = x; return;
        }
        extend ();
        ll mid = (l + r) >> 1;
        if (p <= mid) lft -> put (p, x);
        else rht -> put (p, x);
        val = max (lft -> val, rht -> val);
    }
    
    ll qry (ll ql, ll qr) {
        if (l >= ql && r <= qr) return val;
        extend ();
        ll res = def_value;
        ll mid = (l + r) >> 1;
        if (ql <= mid) res = max (res, lft -> qry (ql, qr));
        if (qr >= mid + 1) res = max (res, rht -> qry (ql, qr));
        return res;
    }
};

class Solution{
	
	public:
	int maxSumIS(int arr[], int n) {
	    Node* root = new Node (0, 1e18);
	    for (int i = 0; i < n; i += 1) {
	        ll mx = arr[i];
	        mx = max (mx, root -> qry (0, arr[i] - 1) + arr[i]);
	        root -> put (arr[i], mx);
	    }
	    
	    int ans = root -> qry (0, 1e18);
	    return ans;
	}
};
