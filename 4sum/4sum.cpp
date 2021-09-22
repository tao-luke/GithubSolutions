class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result{};
        std::sort(nums.begin(),nums.end());
        unsigned char size = nums.size();
        for(unsigned char i = 0;i<size;i++){
            if (i > 0 && nums[i] == nums[i-1]) continue;
            for(unsigned char j = i+1;j < size;j++){
                if (j > i+1 && nums[j] == nums[j-1]) continue;
                unsigned char k = j+1;
                unsigned char l = size-1;
                while(k < l){
                    if (nums[k]+nums[l] < target-nums[i]-nums[j]){
                        k++;
                    }
                    else if (nums[k]+nums[l] > target-nums[i]-nums[j]){
                        l--;
                    }else{
                        result.push_back(vector<int>{nums[i],nums[j],nums[k],nums[l]});
                        while(k+1 < l && nums[k] == nums[k+1])k++;
                        while(l-1 > k && nums[l] == nums[l-1]) l--;
                        k++; l--;
                    }
                }
            }
        }
        return result;
    }
};