/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> preorder(Node* root) {
        vector<int> result{};
        if (root== nullptr) return result;
        stack<Node*> hist{};
        hist.push(root);
        while(!hist.empty()){
            root = hist.top();
            result.push_back(root->val);
            hist.pop();
            for(int i = root->children.size()-1; i>=0;i--){
                hist.push(root->children[i]);
            }
        }
        return result;
    }
};