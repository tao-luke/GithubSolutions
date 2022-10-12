class Solution {
public:
    int init_left(vector<int>& nums){ //returns the last index of negative #
      int l = -1;
      while((l+1 <(int) nums.size()) and nums[l+1] < 0){
        l++;
      }
      return l;
    }
    int get_next_index_and_inc(vector<int>& nums, int& index_1, int& index_2){ //returns the index with smaller # and incr it
      if (index_1 == -1) return index_2++;
      if (index_2 == nums.size()) return index_1--;
      if (-1 * nums[index_1] > nums[index_2]){
          index_2++;
          return index_2-1;
      }
      index_1--;
      return index_1+1;
    }
    vector<int> sortedSquares(vector<int>& nums) {
      if (nums.size() == 1) return vector<int>{nums[0]*nums[0]};
        vector<int> res{};
      int index_1 = init_left(nums);
      int index_2 = index_1 + 1;
      while(index_1 != -1 || index_2 != nums.size()){
        int next_index = get_next_index_and_inc(nums,index_1,index_2);
        res.push_back(nums[next_index]*nums[next_index]);
      }
      return res;
    }
  
};