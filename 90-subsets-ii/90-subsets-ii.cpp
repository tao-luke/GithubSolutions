class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result{};
        vector<int> tmp{};
        helper(result, tmp, nums, 0);
        return result;
    }
    void helper(vector<vector<int>>& result, vector<int>& tmp,const vector<int>& nums, int index){
        result.push_back(tmp);
        for(int i = index; i < nums.size(); i++){
            if (i == index || nums[i] != nums[i-1]) {
                tmp.push_back(nums[i]);
                helper(result, tmp, nums, i+1);
                tmp.pop_back();
            }
        }
    }
};