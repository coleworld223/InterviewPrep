/*
    Hints : 
    1. This is a standard algo so there's little chance, you can think upon your own
    2. Still, try to get through the solution bit by bit, 
*/

/*
    Solution (Explanation) : 
    Visualise a lot of threads coming out from the source going to different nodes till a point of time
    (initially there's only one thread starting and ending at node 'source' with length zero)
    , we always move forward with the current smallest length of thread (we extend the thread to possible nodes)
    
    Try to think upon the following ideas : 
    1. at any point of time the smallest thread we pick, gives us the shortest distance to current node
    (why ?) -> say we are at start, we spread the threads from source, now the smallest length thread 
    will surely be the smallest distance to the node it ends at. You can continue this reasoning further to understand
    why dijekstra gives the shortest path from source to all nodes.
    
    It is okay if you can't understand the above logic, try to come up with your own, But don't just try to cram
    it.
*/


class Solution
{
	public:
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S) {
        using ll = long long;
        ll inf = 2e9;
        vector <int> dis (V, inf);
        vector <bool> vis (V);
        set <pair <int, int>> st;
        dis[S] = 0;
        st.insert ({dis[S], S});
        while (!st.empty()) {
            auto x = *st.begin();
            st.erase (st.begin());
            ll d = x.first, u = x.second;
            if (vis[u]) continue;
            vis[u] = 1;  // why are we using a visited array ? (hint -> a node once relaxed (it put nodes in set, it should not do it again,
                        // because first time it comes to the top, it's with the shortest distance))
            for (auto y : adj[u]) {
                ll v = y[0], w = y[1];
                if (dis[v] > w + dis[u]) {
                    dis[v] = dis[u] + w; // why should we update the distance here only ? (hint -> it helps us put lesser nodes in set)
                    st.insert ({dis[v], v});
                }
            }
        }
        return dis;
    }
};