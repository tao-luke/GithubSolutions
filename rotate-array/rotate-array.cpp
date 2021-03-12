class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int size = nums.size();
        int counter = 0;
        k = k%size;
        vector<int> tmp;
        tmp.resize(size);
        
        for(const auto & e: nums){
            tmp[(counter+k)%size] = e;
            counter++;
        }
        counter = 0;
        for(const auto& e: tmp){
            nums[counter++] = e;
        }
    }
};