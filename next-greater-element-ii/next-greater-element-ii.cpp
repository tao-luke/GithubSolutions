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
        stack<pair<short,int>> hist{};
        hist.push(make_pair(0,nums[0]));
        for(short i = 1;i < size;i++){
            while(hist.top().second < nums[i]){
                result[hist.top().first] = nums[i];
                hist.pop();
                if (hist.empty()){
                    bottom = i;
                    break;
                }
            }
            hist.push(make_pair(i,nums[i]));
        }
        int index = 0;
        while(hist.top().second != nums[bottom]){
            while(nums[index]<= hist.top().second){
                index++;
            }
            result[hist.top().first] = nums[index];
            hist.pop();
            while(hist.top().second < nums[index]){
                result[hist.top().first] = nums[index];
                hist.pop();
            }
        }
        while(!hist.empty()){
            result[hist.top().first] = -1;
            hist.pop();
        }
        return result;
    }
};