class Solution {
public:
    static bool my_sort(vector<int>& a, vector<int>& b){
        return a[1] < b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), my_sort);
        stack<vector<int>> tmp{};
        int ans = 0;
        for(const auto& v: intervals){
            if (tmp.empty() || tmp.top()[1] <= v[0]) tmp.push(v);
            else{
                ans++;
            }
        }
        return ans;
    }
};