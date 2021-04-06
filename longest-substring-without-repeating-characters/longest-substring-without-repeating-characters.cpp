class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int size = s.size();
        if (size < 2) return size;
        unordered_map<char, int> seen{};
        int left = 0;
        int right = 0;
        int largest = 0;
        auto ite = seen.begin();
        for(;right<size;right++){
            ite = seen.find(s[right]);
            if (ite == seen.end()){
                seen.insert(make_pair(s[right],right));
            }else{
                if (ite->second >= left){
                    largest = max(largest, right-left);
                    left = ite->second+1;
                    
                }
                ite->second = right;
            }
        }
        return max(largest,right-left);
    }
};