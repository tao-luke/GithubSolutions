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
    vector<vector<int>> levelOrder(TreeNode* root) {
        map<int,vector<int>> collection{};
        vector<vector<int>> result{};
        record(root,collection,0);
        for(const auto& i:collection){
            result.push_back(std::move(i.second));
        }
        return result;
    }
    void record(TreeNode* root, map<int,vector<int>>& collection, int distance)     {
        if (root == nullptr) return;
        auto ite = collection.find(distance);
        if (ite != collection.end()){ //if found
            ((*ite).second).push_back(root->val);
        }else{
            collection.insert({distance,vector<int>{root->val}});
        }
        record(root->left,collection,distance+1);
        record(root->right,collection,distance+1);
        
    }
};