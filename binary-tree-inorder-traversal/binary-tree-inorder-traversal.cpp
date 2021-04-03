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
        if (root == nullptr) return result;
        stack<pair<TreeNode*, bool>> todo{};
        todo.push(make_pair(root,false)); //map of(node, if we looked at left)
        TreeNode* tmp = root;

        while(!(todo.empty())){
            cout << todo.top().first->val << endl;
            if (todo.top().first->left != nullptr && !(todo.top().second)){
                todo.top().second = true;
                todo.push(make_pair(todo.top().first->left,false));
            }else{
                result.push_back(todo.top().first->val); //push us in.
                tmp = todo.top().first; //save the top
                todo.pop(); //pop the top from stack
                if (tmp->right != nullptr) todo.push(make_pair(tmp->right,false)); //check if top->right is valid, if yes, push
            }
        }
        return result;
    }
};