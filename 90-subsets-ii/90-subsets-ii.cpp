class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        // my mistakeS:
        //      so the way I approached this question, is to divide the big problem to smaller considerations starting from each index.(ofc sort first). then at each index, the question to ask is to include this or dont include this. However, since each duped, we can NOT consider a new start from each point, but only on points where we havent mapped from yet. This would usually suffice to classify as a set and enforce the rules as such, but we want powerset considering without duped sets. This means if we consider a sequence first from a and try its route from a+1, this is fine after n iterations. But once we move to include a+2 with the a, it is unideal to compare with a+1 to see if its duped.
        sort(nums.begin(), nums.end());
        vector<vector<int>> result{};
        vector<int> tmp{};
        result.push_back(tmp);
        for(int i = 0; i < nums.size(); i++){
            if (i == 0 || nums[i] != nums[i-1]) helper(result, tmp, nums, i);
        }
        
        return result;
    }
    void helper(vector<vector<int>>& result, vector<int>& tmp,const vector<int>& nums, int index){
        tmp.push_back(nums[index]);
        result.push_back(tmp);
        int cpy = index;
        index++;
        int previous = -1000;
        while(index != nums.size()){
            if (nums[index] != previous){
                helper(result, tmp, nums, index);
                previous = nums[index];
            } 
            index++;
        }
        tmp.pop_back();
    }
};