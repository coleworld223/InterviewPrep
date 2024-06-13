/*
    Hints : 
    1. Test your basic recurison concepts
*/

/*
    Solution:
    define 
    DFS (node) = visit node and all unvisited children (not just direct children) of 'node'
    DFS (node) = () {
        vis[node] = 1;
        for all direct child of 'node' : DFS (child);
    }

    Note: Almost all recursive methods can be simulated usinng stacks and it is better complexity wise
          because we get free from recursion stack space (that uses space to store function variables etc)
          Also, the time gets reduced
    
    Solution using Stack:
    sketch of an algo should look like:
    1. put the given node on top of stack, visit it
    2. while the stack is not empty, look at the 'node' at the top of the stack,
       if there is an unvisited child of this 'node' push it in stack and go to step 1
       else pop the top of stack and go to step 2
    as soon as stack becomes empty the algo stops

    (You can give it a try to implement it)
    
*/

class Solution {
  public:
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector <int> vis (V), res;
        function <void (int)> DFS = [&] (int u) {
            vis[u] = 1;
            res.push_back(u);
            for (int v : adj[u]) if (!vis[v]) {
                DFS (v);
            }
        };
        DFS(0);
        return res;
    }
};