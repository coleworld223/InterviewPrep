
/*
    Hints : 
    1. DFS is recursion
    2. Try to define a recursive function

*/

/*
    Solution:
    How does recursion work?
    F (par1, par2) if defined to a particular task, we trust that
    it would do the particular task, that's it

    For e.g. DFS is a recursive method (function)
    we define DFS (node) = visit the node 'node' and all unvisited children of 'node'
    Now if DFS (node) does what it says, we can traverse the whole graph 
    in a defined fashion (each edge and each vertex visited one time) (how ?)
    we say 
    DFS (node) -> DFS (all unvis children of 'node')
    This explanation might seem vague (just try to think on your own the concept of 'Recursive Trust')
    This will help

    Now the solution is:
    __clone (node) = it's a function, we define it as : clone node and all uncloned children
                     of 'node' and connect them
    
    

*/

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
const int sz = 101;
class Solution {
public:
    vector <Node*> nodes;
    Node* __clone (Node* root) {
        Node* ret = new Node();
        ret -> val = root -> val;
        nodes[ret -> val] = ret;
        for (auto c : root -> neighbors) {
            if (nodes[c -> val] == NULL) {
                Node* child = __clone (c);
                (ret -> neighbors).push_back(child);
            }
            else {
                (ret -> neighbors).push_back(nodes[c -> val]);
            }
        }
        return ret;
    }
    Node* cloneGraph(Node* node) {
        if (node == NULL) return NULL;
        nodes.resize(101, NULL);
        Node* new_root = __clone (node);
        return new_root;
    }
};