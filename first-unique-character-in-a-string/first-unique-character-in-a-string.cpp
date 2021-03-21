class Solution {
public:
    int firstUniqChar(string s) {
        if (s.size() == 0) return -1;
        unordered_map<char, pair<bool,int>> seen{};
        int counter = 0;
        for(const auto & c: s){
            auto ite = seen.find(c);
            if (ite == seen.end()){
                seen.insert(make_pair(c,make_pair(true,counter)));
            }else{
                (ite->second).first = false;
            }
            counter++;
        }
        int min = INT_MAX;
        bool marker = false;
        for(const auto &e: seen){
            if (((e.second).first)&&((e.second).second < min)){
                min = (e.second).second;
                if (marker == false) marker = true;
            }
        }
        if (marker == false) return -1;
        return min;
    }
};