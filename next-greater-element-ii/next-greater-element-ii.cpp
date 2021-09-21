class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        //3 1 2 5 1
        //5 4 3 2 1 
        //-1
        if (nums.size() == 1) return vector<int>{-1};
        int bottom = 0;
        short size = nums.size();
        vector<int> result(size,0);
        stack<short> hist{};
        hist.push(0);
        for(short i = 1;i < size;i++){
            while(nums[hist.top()] < nums[i]){
                result[hist.top()] = nums[i];
                hist.pop();
                if (hist.empty()){
                    bottom = i;
                    break;
                }
            }
            hist.push(i);
        }
        int index = 0;
        while(nums[hist.top()] != nums[bottom]){
            while(nums[index]<= nums[hist.top()]){
                index++;
            }
            result[hist.top()] = nums[index];
            hist.pop();
            while(nums[hist.top()] < nums[index]){
                result[hist.top()] = nums[index];
                hist.pop();
            }
        }
        while(!hist.empty()){
            result[hist.top()] = -1;
            hist.pop();
        }
        return result;
    }
};