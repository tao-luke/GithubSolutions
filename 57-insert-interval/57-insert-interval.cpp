class Solution {
public:
    void reformat(vector<vector<int>>& intervals, int i,int j){
        if (i == j) return;
        intervals[i][1] = max(intervals[j][1],intervals[i][1]);
        intervals.erase(intervals.begin()+i+1, intervals.begin()+j+1);
    }
    int find(const vector<vector<int>>& intervals, int i){
        int l = 0;
        int r = intervals.size()-1;
        while(l < r){
            int med = l+(r-l+1)/2;
            if (intervals[med][0] <= i){
                l = med;
            }else{
                r = med-1;
            }
        }
        return l;
    }
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if (intervals.empty()) return vector<vector<int>>{newInterval};
        int left_index = find(intervals, newInterval[0]);
        int right_index = find(intervals, newInterval[1]);
        if (intervals[left_index][0] > newInterval[1]){
            intervals.insert(intervals.begin()+left_index,newInterval);
        }else if (intervals[right_index][1] < newInterval[0]){
            intervals.insert(intervals.begin()+right_index+1,newInterval);
        }else{
            if (intervals[left_index][1] < newInterval[0]){
                if (intervals[left_index+1][0] > newInterval[1]){
                    intervals.insert(intervals.begin()+left_index+1,newInterval);
                }else{
                    left_index++;
                }
            }
            intervals[left_index][0] = min(intervals[left_index][0], newInterval[0]);
            intervals[left_index][1] = max(intervals[left_index][1], newInterval[1]);
            reformat(intervals, left_index, right_index);
        }
        
        
        return intervals;
    }
};