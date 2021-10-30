class Solution {
public:
    static bool interSort(const vector<int>& a1, const vector<int>& a2){
        return a1.front() < a2.front();
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),interSort);
        vector<vector<int>> result{};
        result.push_back(intervals[0]);
        for(int i = 1; i < intervals.size();i++){
            if (result.back().back() >= intervals[i].front()){
                result.back().back() = max(intervals[i].back(),result.back().back());
            }else{
                result.push_back(intervals[i]);
            }
        }
        return result;
    }
};