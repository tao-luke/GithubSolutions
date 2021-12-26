class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        // the trick here is we only need to consider the subset where a element is included from EVERY single arrray. Furthermore, we know there are 4 arrays always in total. With that, we can hash table EVERY sum from array 1  and array 2,O(n^2). Then check if the 0-element sum exists in this table for array3 and array4 when the same is repeated.
        int ans = 0;
        unordered_map<int,int> hist{};
        for(const auto& i: nums1) {
            for(const auto& j: nums2) {
                hist[i + j]++;
            }
        }
        for(const auto& i: nums3){
            for(const auto& j: nums4){
                auto ite = hist.find(- (i+j));
                if (ite != hist.end()) {
                    ans+=ite->second;
                }
            }
        }
        return ans;
    }
};