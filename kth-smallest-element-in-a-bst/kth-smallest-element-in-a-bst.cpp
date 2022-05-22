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
    int kthSmallest(TreeNode* root, int k) {
        //in order traversal?
        stack<TreeNode*> todo{};
        TreeNode* curr = root;
        while(curr != nullptr || !todo.empty()){
            while(curr != nullptr){ //push the left things in if im not null
                todo.push(curr);
                curr = curr->left;
            }
            curr = todo.top(); todo.pop();
            if (k == 1) return curr->val;
            k--;
            curr = curr->right;
        }
        return 0;
    }
};