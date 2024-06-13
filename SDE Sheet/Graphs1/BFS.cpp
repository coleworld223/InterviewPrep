/*
    Hints:
    1. BFS requires you to process nodes one level at a time, How can you simulate this
    2. Only after a level is processed completely the next level should be processed
*/

/*
    Solution:
    we can use two vectors V[0], V[1]
    v[0] -> holds cur level nodes, v[1] -> holds next level ('cur level + 1') nodes
    
    Note that the same can be done using queues, (why?)
*/

class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        vector <int> v[2];
        vector <int> vis (V);
        vis[0] = 1;
        v[0].push_back(0);
        vector <int> res;
        while (!v[0].empty()) {
            for (int u : v[0]) {
                res.push_back(u);
                for (int c : adj[u]) if (!vis[c]) {
                    vis[c] = 1;
                    v[1].push_back(c);
                }
            }
            v[0].clear();
            for (int x : v[1]) {
                v[0].push_back(x);
            }
            v[1].clear();
        }
        return res;
    }
};