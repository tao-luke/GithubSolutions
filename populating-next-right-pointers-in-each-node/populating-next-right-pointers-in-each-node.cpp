/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* helper(Node* root, Node* next = nullptr){
        if (root == nullptr) return nullptr;
        root->next = next;
        if (root->left != nullptr){
            helper(root->left,root->right);
            if (next != nullptr){
                helper(root->right,next->left);
            }else{
                helper(root->right);
            }
        }
        return root;
    }
    Node* connect(Node* root) {
        return helper(root);
    }
};