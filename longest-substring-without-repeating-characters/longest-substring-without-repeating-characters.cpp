class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int size = s.size();
        if (size < 2) return size;
        unordered_map<char, int> seen{};
        int left = 0;
        int right = 0;
        int largest = 0;
        for(;right<size;right++){
            if (seen.find(s[right]) == seen.end()){
                seen.insert(make_pair(s[right],right));
            }else{
                largest = max(largest,right-left);
                cout << largest << endl;
                if (s[right-1] == s[right]){
                    left = right;
                    right--;
                }else{
                    right = left;
                    left++;
                    
                }
                
                seen.clear();
            }
        }
        return max(largest,right-left);
    }
};