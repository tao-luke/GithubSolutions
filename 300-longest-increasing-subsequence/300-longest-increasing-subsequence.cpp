class Solution {
public:
    int find_index(const vector<int>& seen, int n){
        int l = 0;
        int r = seen.size()-1;
        while(l < r){
            int med = l+(r-l)/2;
            if (seen[med] >= n){
                r = med;
            }else{
                l = med+1;
            }
        }
        if (seen[l] != n){
            return l;
        }
        return -1;
    }
    int lengthOfLIS(vector<int>& nums) {
        vector<int> seen{};
        for(const auto&n: nums){
            if (seen.empty() || n > seen.back()){
                seen.push_back(n);
            }else{
                int index = find_index(seen,n);
                if (index != -1) seen[index] = n;
            }
            cout << endl;
        }
        return seen.size();
    }
};