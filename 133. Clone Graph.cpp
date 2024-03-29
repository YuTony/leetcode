//https://leetcode.com/problems/clone-graph/

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {}

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
class Solution {
   public:
    Node* cloneGraph(Node* node) {
        if (!node) {
            return NULL;
        }
        if (copies.find(node) == copies.end()) {
            copies[node] = new Node(node->val, {});
            for (Node* neighbor : node->neighbors) {
                copies[node]->neighbors.push_back(cloneGraph(neighbor));
            }
        }
        return copies[node];
    }

   private:
    map<Node*, Node*> copies;
};
