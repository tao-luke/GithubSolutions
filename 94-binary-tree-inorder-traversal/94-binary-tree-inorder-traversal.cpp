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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result{};
        stack<TreeNode*> dp{};
        TreeNode* current = root;
        while(current != NULL || !dp.empty()){
            while(current != NULL){
                dp.push(current);
                current = current->left;
            }
            current = dp.top();
            dp.pop();
            result.push_back(current->val);
            current = current->right;
        }
        return result;
    }
};