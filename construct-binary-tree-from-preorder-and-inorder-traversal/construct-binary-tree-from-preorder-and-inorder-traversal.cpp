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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode* result = helper(preorder, 0, preorder.size(), inorder, 0, inorder.size());
        return result;
    }
    TreeNode* helper(const vector<int>& preorder, int a, int b, vector<int>& inorder, int c, int d){
        if (a == b || c == d) return nullptr;
        TreeNode* node = new TreeNode(preorder[a]);
        int counter = 0;
        while(inorder[c+counter] != node->val){ //find the value in inorder
            counter++;
        }
        node->left = helper(preorder, a+1, a+counter+1, inorder, c, c+counter);
        node->right = helper(preorder, a+counter+1, b, inorder, c+counter+1, d);
        return node;
    }
};