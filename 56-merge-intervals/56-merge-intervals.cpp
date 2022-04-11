class Solution {
public:
    static bool my_sort(vector<int>& a, vector<int>& b){
        return a[0] < b[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), my_sort);
        stack<vector<int>> hist{};
        for(int i = 0; i < intervals.size();i++){
            if (!hist.empty() && hist.top()[1] >= intervals[i][0]){
                hist.top()[0] = min(hist.top()[0], intervals[i][0]);
                hist.top()[1] = max(hist.top()[1], intervals[i][1]);
            }else{
                hist.push(intervals[i]);
            }
        }
        vector<vector<int>> result{};
        while(!hist.empty()){
            result.push_back(hist.top());
            hist.pop();
        }
        return result;
    }
};