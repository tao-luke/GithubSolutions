class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        // BIg oof, I trie to do this O(n), but that is not possible. as at any point, you can only know the intersections by going forward and checking. instead, it is better to focus on the rooms 
        // either abstract rooms as min-heap or keep 2 arrays of start and end times. iterate thourgh the start times, and keep a ptr for end times. for every start time, check the end ptr time, if a room has finished, use it.(no add). if no room openned up, we need another room. 
        vector<int> start{};
        vector<int> end{};
        for(const auto & v: intervals){
            start.push_back(v.front());
            end.push_back(v.back());
        }
        sort(start.begin(),start.end());
        sort(end.begin(), end.end());
        auto ite = end.begin();
        int result = 0;
        for(const auto & s: start){
            if (s >= *ite){
                // a room openned up
                ite++;
            }else{
                //no room openned up
                result++;
            }
        }
        return result;
    }
};