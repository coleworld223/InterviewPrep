/*
    Hints:
    1. if a (0 / 1) coloring is possible, we can flip to create a (1 / 0) coloring also
    2. since its binary coloring (1 or 0), one approach can be a forces solution
    3. try to see it from bfs / dfs
*/

/*
    Solution:
    what do I mean by forced solution? any node can be '0' or '1', and once
    we decide for a node (say it will be '0'), then all its neigbors will get a forces '1' color
    and consecutively other nodes will also be forced

    So, we can start from some node (color it any of 0 or 1 (why it doesn't matter ? Hint1))
    and force color all other nodes, if we violate the condition anywhere
    it means, it's not possible to binary color the graph (why violation statring from only node sufficiently imply this?)
    (the answer lies in structure of Bipartite graph (odd, even cycles) ? (give it a thought on your own))
*/

class Solution {
public:
    bool isBipartite(vector<vector<int>>& g) {
        int n = g.size();
        bool bip = 1;
        // DFS Solution:
        // vector <int>  col (n, -1);
        // function <void (int, int)> DFS = [&] (int u, int c) {
        //     col[u] = c;
        //     for (int v : g[u]) {
        //         if (col[v] == -1) DFS (v, 1 - col[u]);
        //         else if (col[v] == col[u]) bip = 0;
        //     }
        // };
        // for (int u = 0; u < n; u += 1) if (col[u] == -1) {
        //     DFS (u, 0);
        // }

        //BFS solution
        vector <int> col (n, -1);
        auto BFS = [&] (int u, int c) {
            queue <int> q;
            q.push (u);
            col[u] = c;
            while (!q.empty()) {
                int u = q.front();
                q.pop();
                for (int v : g[u]) {
                    if (col[v] == -1) {
                        q.push (v);
                        col[v] = 1 - col[u];
                    }
                    else if (col[v] == col[u]) bip = 0;
                }
            }
        };

        for (int u = 0; u < n; u += 1) {
            if (col[u] == -1) {
                BFS (u, 0);
            }
        }

        return bip;
    }
};