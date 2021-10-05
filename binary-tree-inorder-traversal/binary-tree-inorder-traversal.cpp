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
    TreeNode* findRightMost(TreeNode* root){
        while(root->right){
            root = root->right;
        }
        return root;
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result{};
        if (!root) return result;
        while(root){
            if (root->left){
                findRightMost(root->left)->right = root;
                TreeNode* tmp = root->left;
                root->left = nullptr;
                root = tmp;
            }else{
                result.push_back(root->val);
                root = root->right;
            }
        }
        return result;
//         vector<int> result{};
//         if (root == nullptr) return result;
//         stack<TreeNode*> hist{};
//         hist.push(root);
//         while(!hist.empty()){
//             root = hist.top();
//             if (root->left == nullptr){
//                 result.push_back(root->val);
//                 hist.pop();
//                 if (root->right) hist.push(root->right);
//             }else{
//                 hist.push(root->left);
//                 root->left = nullptr;
//             }
            
//         }
//         return result;
    }
};