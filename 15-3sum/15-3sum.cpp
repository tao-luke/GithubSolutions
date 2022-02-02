class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result{};
        for(int i = 0; i < nums.size();i++){
            if (i != 0 && nums[i] == nums[i-1]) continue;
            int j = i+1;
            int k = nums.size()-1;
            while(j < k){
                if (nums[j]+nums[k] == -nums[i]){
                    result.push_back(vector<int>{nums[i],nums[j],nums[k]});
                    j++;
                    while(j < k && nums[j-1] == nums[j]) j++;
                    k--;
                    while(j < k && nums[k] == nums[k+1]) k--;
                }else if (nums[j]+nums[k] < -nums[i]){
                    j++;
                    while(j < k && nums[j-1] == nums[j]) j++;
                }else{
                    k--;
                    while(j < k && nums[k] == nums[k+1]) k--;
                }
            }
        }
        return result;
    }
};