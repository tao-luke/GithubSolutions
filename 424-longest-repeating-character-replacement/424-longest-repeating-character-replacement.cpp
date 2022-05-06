class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int> seen{};
        int l = 0;
        int r = 0;
        int ans = 0;
        int local_size = 0;
        char freq = 1;
        while(r < s.size()){
            char c = s[r];
            seen[c]++;
            local_size++;
            if (freq == 1 or seen[c] > seen[freq]) freq = c;

            while (local_size - seen[freq] > k){
                seen[s[l]]--;
                l++;
                local_size--;
                for(const auto& p: seen){
                    if (p.second > seen[freq]) freq = p.first;
                }
            }
            ans = max(ans,local_size);
            r++;
        }
        return ans;
    }
};