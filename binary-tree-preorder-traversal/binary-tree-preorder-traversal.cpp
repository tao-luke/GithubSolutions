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
    //recursion'
    void helper(vector<int>& result,TreeNode* root){
        if (root == nullptr) return;

        result.push_back(root->val);
                helper(result,root->left);
        helper(result,root->right);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result{};
        helper(result,root);
        return result;
    }
};