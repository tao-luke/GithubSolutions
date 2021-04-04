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

//solution idea: consider the current node lvl to have some orientatin of printing LtoR, the lvl+1 must be printing !LtoR. To this end, we construct the "image" of 2 stacks. one of current lvl and one of next lvl. assume the current stack is in order of orientation, we just read and pop each node and insert to result vector. To accomadate for the reverse LtoR in the next lvl, simply insert the node in the same order as we are reading in the current stack(they will be flipped due to stack strucutre).
class Solution {
public:
    
    void helper(vector<vector<int>>& result,stack<pair<TreeNode*, int>>& todo,bool LtoR){
        stack<pair<TreeNode*,int>> next{};
        while (!todo.empty()){
            if (todo.top().first == nullptr){
                todo.pop();
                continue;
            }
            int val = todo.top().first->val;
            int lvl = todo.top().second;
            if (lvl >= result.size()) result.push_back(vector<int>{});
            result[lvl].push_back(val); //add to answer arr
            if (LtoR){
                next.push(make_pair(todo.top().first->left,lvl+1));
                next.push(make_pair(todo.top().first->right,lvl+1));
            }else{
                next.push(make_pair(todo.top().first->right,lvl+1));
                next.push(make_pair(todo.top().first->left,lvl+1));
            }
            todo.pop();
        }
        if (next.empty()) return;
        helper(result,next,!LtoR);
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result {};
        if (root == nullptr) return result;
        stack<pair<TreeNode*, int>> current{};
        current.push(make_pair(root,0));
        helper(result,current,true);
        return result;
    }
};