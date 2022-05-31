class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result{};
        vector<int> tmp{};
        helper(tmp,result,nums,0);
        return result;
    }
    void helper(vector<int>& tmp, vector<vector<int>>& res, const vector<int>& nums, int i){
        if (i >= nums.size()){
            res.push_back(tmp);
            return;
        }
            
        tmp.push_back(nums[i]);
        helper(tmp,res,nums,i+1);
        tmp.pop_back();
        helper(tmp,res,nums,i+1);
        return;
    }
};