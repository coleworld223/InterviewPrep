/*
    Hints : 
    1. For a dfs solution, think of how a dfs visits vertexes
    2. For a bfs solution, think of how degrees of vertices can be exploited
    
    3. Don't think for too long, just try to get an idea, as these are standard algos (atleast the bfs one)
*/


/*
    Soltuion (BFS):
    A topo sort exists only when there is no cycle
    there is no cycle -> at least one vertex has zero indegree
    keep removing the zero indegree vertices (and corresponding edges)
    the vertex removed earlier in order come earlier in topo sort (or topo sort is the order of removal of vertices (why?))
    
    Solution (DFS):
    A dfs visits all the depth starting from a node (it is defined in such a way)
    note that, dfs of a node ends only after dfs of every node reachable from it ends
    This is definition of toposort
    so we can push a node in ordering (topo sort) when the dfs (node) is ending
*/
class Solution
{
	public:
	vector<int> topoSort(int V, vector<int> adj[]) {
	    // DFS Solution
	   vector <int> tp, vis (V);
	   function <void (int)> DFS = [&] (int u) {
	       vis[u] = 1;
	       for (int v : adj[u]) if (!vis[v]) {
	           DFS (v);
	       }
	       tp.push_back(u);
	   };
	   for (int u = 0; u < V; u += 1) if (!vis[u]) {
	       DFS (u);
	   }
	   reverse (tp.begin(), tp.end());
	   return tp;
	    
	    //BFS Soltuion
	    vector <int> indeg (V), tp;
	    queue <int> q;
	    for (int u = 0; u < V; u += 1) {
	        for (int v : adj[u]) {
	            indeg[v] += 1;
	        }
	    } 
	    for (int u = 0; u < V; u += 1) {
	        if (indeg[u] == 0) q.push (u);
	    }
	    while (!q.empty()) {
	        int u = q.front();
	        q.pop();
	        tp.push_back(u);
	        for (int v : adj[u]) {
	            indeg[v]--;
	            if (indeg[v] == 0) {
	                q.push(v);
	            }
	        }
	    }
	    return tp;
	}
};