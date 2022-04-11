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
        if (node == NULL) return NULL;
        queue<Node*> bfs_q{};
        unordered_map<Node*, Node*> mapping{};
        bfs_q.push(node);
        Node* result = new Node(node->val);
        mapping.insert(make_pair(node, result));
        while(!bfs_q.empty()){
            Node* current = bfs_q.front();
            bfs_q.pop();
            for(int i = 0; i < current->neighbors.size();i++){
                if (mapping.find(current->neighbors[i]) == mapping.end()){
                    mapping.insert(make_pair(current->neighbors[i],new Node(current->neighbors[i]->val)));
                    bfs_q.push(current->neighbors[i]);
                }
                mapping[current]->neighbors.push_back(mapping[current->neighbors[i]]);
            }
        }
        return result;
    }
};