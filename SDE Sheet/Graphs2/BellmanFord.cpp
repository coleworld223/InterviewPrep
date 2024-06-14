/*
    Hints : 
    1. It's a standard algo
    2. Try going through the algo bit by bit, and understand why it works
    
*/

/*
    Solution : 
    Argument -> If we have reached at least one vertex with the shortest possible distance and there are nodes reachable from it
                and we try to use all the edges to reach somewhere, we will find the shortest distance
                to atleast one more node (why ? )
                
               using above fact it's easy to see, we will reach all the nodes with correct distance (shortest distance)
               in at most (V - 1) iterations, where V = no. of nodes
               In the Vth iteration, if we still make distance to some node smaller, it will surely mean there's a
               negative cycle in the graph

*/

class Solution {
  public:
    vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
        vector <int> dis (V, 1e8);
        dis[S] = 0;
        for (int p = 0; p < V; p += 1) {
            bool upd = 0;
            for (auto x : edges) {
                int u = x[0], v = x[1], wt = x[2];
                if (dis[u] != 1e8 && dis[v] > dis[u] + wt) {
                    dis[v] = dis[u] + wt;
                    upd = 1;
                }
            }
            if (p == V - 1 && upd) {
                return {-1};
            }
        }
        return dis;
    }
};