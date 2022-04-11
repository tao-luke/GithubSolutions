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
    Node* cloneGraph(Node* node) {
        if (node == NULL) return node;
        unordered_map<Node*, Node*> mapping{};
        return helper(node,mapping);
    }
    Node* helper(Node* node, unordered_map<Node*,Node*>& mapping){
        Node* cpy = new Node(node->val);
        mapping.insert(make_pair(node,cpy));
        for(int i = 0; i < node->neighbors.size();i++){
            auto ite = mapping.find(node->neighbors[i]);
            if (ite != mapping.end()){
                cpy->neighbors.push_back(ite->second);
            }else{
                cpy->neighbors.push_back(helper(node->neighbors[i],mapping));
            }
        }
        return cpy;
    }
};