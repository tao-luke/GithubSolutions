class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,unsigned short> seen{};
        unsigned short size = nums.size();
        for(unsigned short i = 0; i < size;i++){
            auto ite = seen.find(target-nums[i]);
            if (ite != seen.end()){
                return vector<int>{i,ite->second};
            }
            seen.insert(make_pair(nums[i],i));
        }
        return vector<int>{};
    }
    
};