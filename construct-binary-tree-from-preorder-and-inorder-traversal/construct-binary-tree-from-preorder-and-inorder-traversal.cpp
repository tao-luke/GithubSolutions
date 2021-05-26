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
    TreeNode* helper(const vector<int>& preorder, const vector<int>& inorder, int&& a, int&& b,int&& startFrom){
        if (a == b){
            return nullptr;
        }
        TreeNode* root = new TreeNode(preorder[a]);
        if (b - a == 1){
            return root;
        }else{
            int i = startFrom;
            while(inorder[i] != preorder[a]){
                i++;
            }
            i= i - startFrom;
            root->left = helper(preorder,inorder,a+1,a+1+i,move(startFrom));
            root->right = helper(preorder,inorder,a+1+i,move(b),startFrom+i+1);
        }
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return helper(preorder,inorder,0,preorder.size(),0);
    }
};