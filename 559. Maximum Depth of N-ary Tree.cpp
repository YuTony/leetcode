//https://leetcode.com/problems/maximum-depth-of-n-ary-tree/
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    int maxDepth(Node* root) {
        if (!root) return 0;
        int max = 0;
        for (Node* next : root->children) {
            int t = maxDepth(next);
            if (max < t) max = t;
        }
        return 1 + max;
    }
};
