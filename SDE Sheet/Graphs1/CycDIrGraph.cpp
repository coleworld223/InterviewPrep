/*
    Hints:
    1. Create a graph out of the problem, can you reduce the problem to 
       some other problem
    2. How does a Cycle in made 'graph' affects out answer
*/

/*
    Solution:
    1. A sufficient and necessary condition for answer to be 'true' is 
       there should be no cycle in a graph (where edges are (a[i] -> b[i]))
       (why ? )

    There are two methods for finding a cycle in a directed graph
    1. Using DFS
       think of how DFS works -> see dfs as stretching a infinite 
       stretchable thread, as we move to some node we stretch this thread till that node
       when we move back from a node, we shrink the thread till the previous node

       at any point of time we have path that the thread is covering, 
       Now a cycle exists only when we reach at a node where thread alreay lies (or that it's already in out cur path)

       This can be maintained using (Pathvis array) -> see implementation (only after you try yourself) for better understanding

    2. Using bfs
       If the graph has no cycles, note that there will be atleast one node
       with indegree 0 (why?) 
       we can remove this node and edges that go out of it, removing this node 
       can not create a cycle, thus the resulting graph will also not have a cycle,
       keep removing nodes till the graph is empty

       How can this help to find if a cycle exists
       till there is a node with indeg[node] = 0
       remove it and edges going out of it
       if the graph becomes empty -> no cycle
       else -> cycle
       (prove why?)
*/

class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& p) {
        vector <vector <int>> a (n);
        for (auto x : p) {
            int u = x[0], v = x[1];
            a[u].push_back(v);
        }
        //DFS solution;
        vector <bool> vis (n), pathVis (n);
        bool cyc = 0;
        function <void (int)> dfs = [&] (int u) {
            vis[u] = 1;
            pathVis[u] = 1;
            for (int v : a[u]) {
                if (!vis[v]) dfs (v);
                else if (pathVis[v]) cyc = 1;
            }
            pathVis[u] = 0;
        };

        for (int u = 0; u < n; u += 1) if (!vis[u]) {
            dfs (u);
        }

        return cyc == 0;

        /*****************************************************************************************************/
        
        //BFS solution;

        // int cnt = 0;
        // queue <int> q;
        // vector <int> indeg (n);
        // for (auto x : p) {
        //     int v = x[1];
        //     indeg[v] += 1;
        // }
        // for (int u = 0; u < n; u += 1) {
        //     if (indeg[u] == 0) {
        //         q.push (u);
        //     }
        // }

        // while (!q.empty()) {
        //     int u = q.front();
        //     q.pop();
        //     cnt += 1;
        //     for (int v : a[u]) {
        //         indeg[v]--;
        //         if (indeg[v] == 0) {
        //             q.push (v);
        //         }
        //     }
        // }

        // return (cnt == n);
    }
};