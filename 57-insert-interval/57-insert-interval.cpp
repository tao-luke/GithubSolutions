class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        // push in the strictly less thans,
        // merge the overlaps
        // push in the strictly greater thans.
        int index = 0;
        vector<vector<int>> result{};
        while(index < intervals.size() && intervals[index][1] < newInterval[0]){
            result.push_back(intervals[index]);
            index++;
        }
        while(index < intervals.size() && intervals[index][0] <= newInterval[1]){
            newInterval[0] = min(newInterval[0], intervals[index][0]);
            newInterval[1] = max(newInterval[1], intervals[index][1]);
            index++;
        }
        result.push_back(newInterval);
        while(index < intervals.size()){
            result.push_back(intervals[index]);
            index++;
        }
        return result;
    }
};