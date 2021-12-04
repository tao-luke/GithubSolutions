class Solution {
public:
    void replaceHelper(vector<int>& dp, int n){
        //find the least index with elem that is bigger than n
        int left = 0;
        int right = dp.size()-1;
        while(left < right){
            int mid = left + (right-left)/2;
            if (dp[mid] > n){
                right = mid;
            }else{
                left = mid+1;
            }
        }
        if (left-1 >= 0 && dp[left-1] == n) return; //we found the least index where elem is > n, but we cant extend here IF the previous index is equal to this number. This is because we ONLY want strict increase set.
        dp[left] = n;
    }
    int lengthOfLIS(vector<int>& nums) {
        // 2 options when encountering an element:1) it is big big, as in it can directly extend to our best guess.2) it is small, we dont know if its helpful as we are offline.
        //keep a unordered_map of length to end elem(best largest). essentialy a mapping of length to the best possible end it has(which means it has all the correct parts)
        // therefore we need to keep track of each possibility of length. encounter num n, 1) check if its big enough to extend our best.2) if not, check iteratively for each length of our best to 1. find the one that its big enough to extend off of and updte that mapping of length to this new n.
        // reasoning: consider our current state best has length (l) and good big (g). if new n is > g then insert mapping l+1 to n, if not, find best state that has length (l_smaller) and a good small big (g_smaller) such that n > g_smaller. At this point, since n is smaller than the mapping of l_smaller+1, we essentially replace the l_smaller+1 mapping to this new n that is smaller than the old mapped good big.
        // space(answ.length^2), run-time (nlogn) if we use something like binary search to find the l_smaller mapping
        // but we only care about the ends. essentially the map would contain N points, or we can represent this as just an vector. where we each time we either extend or replace to it. the replace would be like a discard of the old l_smaller+1 (we find this using binary search)
        vector<int> dp{};
        for(const auto& n: nums){
            // for(const auto& e: dp){
            //     cout << e << " ";
            // }
            // cout << endl << endl;
            if (dp.empty() || dp.back() < n) dp.push_back(n);
            else replaceHelper(dp,n);
        }
        return dp.size();
    }
};