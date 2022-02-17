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

class Solution {
public:
    Node* visit_dup(Node* node, unordered_map<Node*,Node*>& mapping){
        if (node == NULL) return NULL;
        Node* new_node = new Node(node->val);
        mapping.insert(make_pair(node,new_node));
        for(Node* n: node->neighbors){
            if (mapping.count(n) != 0) new_node->neighbors.push_back(mapping[n]);
            else new_node->neighbors.push_back(visit_dup(n,mapping));
        }
        return new_node;
    }
    Node* cloneGraph(Node* node) {
        unordered_map<Node*, Node*> mapping{};
        return visit_dup(node, mapping);
    }
};