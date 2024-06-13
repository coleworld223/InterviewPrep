/*
    Hints:
    1. Model into a graph, what could be the edges
    2. How does BFS/DFS visit nodes in an undirected graph
*/

/*
    Solution:

    BFS/DFS completely visits a connected component, if it is called
    for any of component's nodes

    ans = count of BFS/DFS called
*/


class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector <vector <bool>> vis (n, vector <bool> (m));
        auto valid = [&] (int x, int y) -> bool {
            return x >= 0 && y >= 0 && x < n && y < m && grid[x][y] == '1';
        };
        function <void (int, int)> DFS = [&] (int x, int y) {
            for (int dx = -1; dx <= 1; dx += 1) {
                for (int dy = -1; dy <= 1; dy += 1) if (abs (dx) + abs (dy) == 1) {
                    int nx = x + dx, ny = y + dy;
                    if (valid (nx, ny) && !vis[nx][ny]) {
                        vis[nx][ny] = 1;
                        DFS(nx, ny);
                    }
                }
            }
        };

        int res = 0;

        for (int x = 0; x < n; x += 1) {
            for (int y = 0; y < m; y += 1) {
                if (valid (x, y) && !vis[x][y]) {
                    vis[x][y] = 1;
                    DFS (x, y);
                    res += 1;
                }
            }
        }
        return res;
    }
};