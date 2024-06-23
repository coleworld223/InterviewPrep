class Solution {
public:
    int minimumSum(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int rp = -1, cp = -1;
        for (int i = 0; i < n; i += 1) {
            for (int j = 0; j < m; j += 1) if (grid[i][j] == 1) {
                rp = i; cp = j; break;
            }
            if (rp != -1) break;
        }
        
        auto intersect = [&] (vector <int> a, vector <int> b) -> bool {
            if (a[1] < b[0] || b[1] < a[0]) return 0;
            if (a[3] < b[2] || b[3] < a[2]) return 0;
            return 1;
        };
        
        auto mini = [&] (int &x, int y) -> void {
            x = min (x, y);
        };
        
        auto maxi = [&] (int &x, int y) -> void {
            x = max (x, y);
        };
        
        int ans = 1000;
        
        for (int r2 = rp; r2 < n; r2 += 1) {
            for (int c1 = 0; c1 <= cp; c1 += 1) {
                for (int c2 = cp; c2 < m; c2 += 1) {
                    vector <vector <int>> t = grid;
                    for (int i = rp; i <= r2; i += 1) {
                        for (int j = c1; j <= c2; j += 1) {
                            t[i][j] = -1;
                        }
                    }
                    vector <int> fc (m, -1), lc (m, -1), fr (n, -1), lr (n, -1);
                    array <int, 2> r = {100, -1};
                    array <int, 2> c = {100, -1};
                    for (int j = 0; j < m; j += 1) {
                        for (int i = 0; i < n; i += 1) {
                            if (t[i][j] == 1) {
                                mini (r[0], i);
                                maxi (r[1], i);
                                mini (c[0], j);
                                maxi (c[1], j);
                            }
                        }
                        if (r[0] > r[1]) {
                            fc[j] = 0; continue;
                        }
                        vector <int> fir = {r[0], r[1], c[0], c[1]};
                        vector <int> sec = {rp, r2, c1, c2};
                        if (!intersect (fir, sec)) {
                            fc[j] = (r[1] - r[0] + 1) * (c[1] - c[0] + 1);
                        }
                    }
                    
                    r = {100, -1};
                    c = {100, -1};
                    
                    for (int j = m - 1; j >= 0; j -= 1) {
                        for (int i = 0; i < n; i += 1) {
                            if (t[i][j] == 1) {
                                mini (r[0], i);
                                maxi (r[1], i);
                                mini (c[0], j);
                                maxi (c[1], j);
                            }
                        }
                        if (r[0] > r[1]) {
                            lc[j] = 0; continue;
                        }
                        vector <int> fir = {r[0], r[1], c[0], c[1]};
                        vector <int> sec = {rp, r2, c1, c2};
                        if (!intersect (fir, sec)) {
                            
                            lc[j] = (r[1] - r[0] + 1) * (c[1] - c[0] + 1);
                        }
                    }
                    
                    r = {100, -1};
                    c = {100, -1};
                    
                    for (int i = 0; i < n; i += 1) {
                        for (int j = 0; j < m; j += 1) {
                            if (t[i][j] == 1) {
                                mini (r[0], i);
                                maxi (r[1], i);
                                mini (c[0], j);
                                maxi (c[1], j);
                            }
                        }
                        if (r[0] > r[1]) {
                            fr[i] = 0; continue;
                        }
                        vector <int> fir = {r[0], r[1], c[0], c[1]};
                        vector <int> sec = {rp, r2, c1, c2};
                        if (!intersect (fir, sec)) {
                            fr[i] = (r[1] - r[0] + 1) * (c[1] - c[0] + 1);
                        }
                    }
                    
                    r = {100, -1};
                    c = {100, -1};
                    
                    for (int i = n - 1; i  >= 0; i -= 1) {
                        for (int j = 0; j < m; j += 1) {
                            if (t[i][j] == 1) {
                                mini (r[0], i);
                                maxi (r[1], i);
                                mini (c[0], j);
                                maxi (c[1], j);
                            }
                        }
                        if (r[0] > r[1]) {
                            lr[i] = 0; continue;
                        }
                        vector <int> fir = {r[0], r[1], c[0], c[1]};
                        vector <int> sec = {rp, r2, c1, c2};
                        if (!intersect (fir, sec)) {
                            lr[i] = (r[1] - r[0] + 1) * (c[1] - c[0] + 1);
                        }
                    }
                    
                    int ar = (r2 - rp + 1) * (c2 - c1 + 1);
                    for (int i = 0; i < n - 1; i += 1) {
                        if (fr[i] != -1 && lr[i + 1] != -1) {
                            ans = min (ans, ar + fr[i] + lr[i + 1]);
                        }
                    }
                    for (int j = 0; j < m - 1; j += 1) {
                        if (fc[j] != -1 && lc[j] != -1) {
                            ans = min (ans, ar + fc[j] + lc[j + 1]);
                        }
                    }
                }
            }
        }
        
        return ans;
    }
};