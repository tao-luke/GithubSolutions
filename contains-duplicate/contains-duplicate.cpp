class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> seen{};
        for(const auto& e: nums){
            if(seen.count(e)){
                return true;
            }
            seen.insert(e);
        }
        return false;
    }
};