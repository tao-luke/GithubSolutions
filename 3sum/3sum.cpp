class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if (nums.size() < 3){
            return {};
        }
        sort(nums.begin(),nums.end());
        vector<vector<int>> result{};
        for(int i = 0; i <= nums.size() - 3;i++){
            cout << i << endl;
            if (i != 0 && nums[i] == nums[i-1]) continue;
            int j = i+1;
            int k = nums.size()-1;
            while (j < k){
                if (-nums[i] == nums[j]+nums[k]){
                    result.push_back(vector<int>{nums[i],nums[j],nums[k]});
                }
                if (-nums[i] < nums[j]+nums[k]){ //too big
                    k--;
                    while(k > j && nums[k] == nums[k+1]){
                        k--;
                    }
                    continue;
                }
                j++;
                while(j < k && nums[j] == nums[j-1]){
                    j++;
                }
            }
        }
        return result;
    }
};