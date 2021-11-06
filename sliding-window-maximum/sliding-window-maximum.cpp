class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // calculate max of first window, keep the index. on every pass, 2 options. If index is no longer considered, find new max index. Else, compare max index to new index, and update to larger.
        // However, there is an issue with this. With random cases, this is fine, but the worst case is O(kn). imagine the case of decreasing sequence. then with each one step forward, the highest is out of bound, and we search forward k steps.
        // instead, we are forgetting an important property. suppose some sequence a .... b .....if the distance of (b-a) < k and nums[b] >= nums[a] and we are at least on index a. then a is ireelevant. This can be seen in the 2 seperate worst box starting from a. b is used instea of a. and when a is out of bound, we dont care. This can be built and abstracted with an deque, and with each num being added or popped only once, O(n) is achieved.
        vector<int> result{};
        deque<int> indexQ{};
        for(int i = 0; i < nums.size();i++){
            while(!indexQ.empty() && nums[indexQ.back()] <= nums[i])indexQ.pop_back();
            indexQ.push_back(i);
            if (i >= k-1) result.push_back(nums[indexQ.front()]);
            if (indexQ.front() < i-k+2) indexQ.pop_front();
        }
        return result;
    }
};