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
    // struct bubble{
    //     int val;
    //     bool null;
    //     bubble(int val, bool null):val{val},null{null}{
    //     }
    //     bool equal(int num){
    //         return val==num;
    //     }
    //     bool equal(bool tmp){
    //         return null;
    //     }
    // };
    // bool isSymmetric(TreeNode* root) {
    //     if (root == nullptr) return true;
    //     if (root->left == nullptr && root->right == nullptr) return true;
    //     if (root->left == nullptr || root->right == nullptr) return false;
    //     vector<bubble> tree1{};
    //     record(root->left,tree1);
    //     int counter = 0;
    //     return validate(root->right,tree1,counter);
    // }
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) return true;
        if (root->left == nullptr && root->right == nullptr) return true;
        if (root->left == nullptr || root->right == nullptr) return false;
        return helper(root->left, root->right);
    }
    bool helper(TreeNode*n1, TreeNode*n2){
        if (n1 == nullptr && n2 == nullptr) return true;
        if (n1 == nullptr || n2 == nullptr) return false;
        return (n1->val == n2->val)&&(helper(n1->left, n2->right) && helper(n1->right,n2->left));
    }
//     bool validate(TreeNode* root, vector<bubble>& tree,int& index){
//         if (root == nullptr) {
//             return tree[index++].equal(true);
//         }
            
//         if (!(tree[index++].equal(root->val))) return false;
//         return (validate(root->right,tree,index)&&validate(root->left,tree,index));
//     }
//     void record(TreeNode* root, vector<bubble>& tree){
//         if (root == nullptr) {
//             tree.push_back({-1,true});
//             return;
//         }
//         tree.push_back({root->val,false});
//         record(root->left,tree);
//         record(root->right,tree);
//     }
};