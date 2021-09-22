class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        // to be more than n/3, there could be at most 2 numbers.
        if (nums.size() < 3){
            if (nums.size() == 1) return nums;
            if (nums[0] == nums[1]) return vector<int>{nums[0]};
            return nums;
        } 
        int num1 = 0;
        int num2 = 0;
        int size = nums.size();
        int freq1 = 0;
        int freq2 = 0;

        for(int i = 0; i < size;i++){
            if (nums[i] == num1){
                freq1++;
            }else if (nums[i] == num2){
                freq2++;
            }else{
                if (freq1 == 0){
                    num1 = nums[i];
                    freq1 = 1;
                    continue;
                }else if (freq2 == 0){
                    num2 = nums[i];
                    freq2 = 1;
                    continue;
                }
                freq1--;
                freq2--;
            }
        }
        // 3 1 3 1 1
        vector<int> result{};
        freq1 = 0;
        freq2 = 0;
        for(const auto& n:nums){
            if (n == num1) freq1++;
            else if (n == num2) freq2++;
        }
        if (freq1 > floor(size/(double)3.0)) result.push_back(num1);
        if (freq2 > floor(size/(double)3.0)) result.push_back(num2);
        return result;
    }
};