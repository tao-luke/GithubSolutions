/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* node) {
        //solve the problem by consider diagnal layers to the left. do the left most, and unwind from there.
        vector<int> result{};
        stack<TreeNode*> todo{};
        while(node != nullptr || !todo.empty()){
            // for each node, we first add all its left parts in
            while(node != nullptr){
                todo.push(node);
                node = node->left;
            }
            //at the very left part
            node = todo.top(); todo.pop();
            result.push_back(node->val);
            node = node->right;
            // move node to the right side, which is where we need to go next
            //since order is left, me, then right. for left most, its just me and right.
        }
        return result;
    }
};