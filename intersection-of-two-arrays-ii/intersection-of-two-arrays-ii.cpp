class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        int size1 = nums1.size();
        int size2 = nums2.size();
        vector<int>result{};
        if (size1 == 0 || size2 ==0) return result;
        unordered_map<int,int> seen{};
        vector<int>* larger = &nums1;
        vector<int>* smaller = &nums2;
        if (size1< size2){
            larger = &nums2;
            smaller = &nums1;
        }
        for(const auto& e: *smaller){
            const auto tmp = seen.find(e);
            if (tmp == seen.end()){
                seen.insert({e,1});
            }else{
                tmp->second++;
            }
        }
        for(const auto&e: *larger){
            const auto tmp = seen.find(e);
            if (tmp != seen.end()){
                if (tmp->second <=0) continue;
                result.push_back(e);
                tmp->second--;
            }
        }
        return result;
    }
};