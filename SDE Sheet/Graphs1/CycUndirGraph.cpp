/*
    Hints:
    1. Do something with dfs or bfs
*/

/*
    Solution:
    It's enough to know how dfs or bfs visits nodes in an undirected graph to find a cycle
    How ? 
    say we are at a particular node during dfs and we have already visited some nodes
    Now if any edge takes us to a prev vis node, what does that mean -> it means we can reach that node from 
    one more path (other than the cur edge) -> means cycle
    
    Similar can be thought for bfs as well
    
    Now, There can be other solutions 
    One involves DSU which is described below
    
    DSU -> {
        a date structure that does the following
        consider a set of node, we wish to keep joining two chosen nodes (as given to us) and at some moment
        we need to find if two points belong to same connected component
        
        DSU does these two things very fast
        
        For a detailed explanation -> you can always go to (USACO GUIDE WEBSITE (TOPIC)), and read
    }
    
    we keep adding edges one by one
    at any point it we add an edge which connects two nodes in the same connected component, we're so done
*/

struct DSU {
    vector <int> par, siz;
    DSU (int n) {
        init(n);
    }
    void init (int n) {
        par.resize(n);
        iota(par.begin(), par.end(), 0);
        siz.resize(n, 1);
    }
    int find (int x) {
        if (par[x] == x) return x;
        return par[x] = find (par[x]);
    }
    bool merge (int x, int y) {
        x = find (x);
        y = find (y);
        if (x == y) return false; // merge did not occur
        if (siz[x] < siz[y]) swap (x, y);
        siz[x] += siz[y];
        par[y] = x;
    }
};

class Solution {
  public:
    bool isCycle(int V, vector<int> adj[]) {
        set <array <int, 2>> st;
        for (int u = 0; u < V; u += 1) {
            for (int v : adj[u]) {
                st.insert ({min (u, v), max (u, v)});
            }
        }
        vector <array <int, 2>> e;
        for (auto x : st) {
            int u = x[0], v = x[1];
            e.push_back({u, v});
        }
        DSU d (V);
        for (auto x : e) {
            int u = x[0], v = x[1];
            if (d.merge (u, v) == 0) return 1;
        }
        return 0;
    }
};
