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
    TreeNode* sortedArrayToBST(const vector<int>& nums) {
        return sortHelper(nums,0,nums.size()-1);
    }
    TreeNode* sortHelper(const vector<int>& nums,int a,int b){
        if (b<a) return nullptr;
        if (b==a) return new TreeNode(nums[a]);
        int tmp = ((b-a)/2)+a;
        return new TreeNode(nums[tmp],sortHelper(nums,a,tmp-1),sortHelper(nums,tmp+1,b));
        
    }
};