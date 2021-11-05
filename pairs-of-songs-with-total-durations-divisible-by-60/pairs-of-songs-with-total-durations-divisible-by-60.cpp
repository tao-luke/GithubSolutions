class Solution {
public:
    // we can treat this question similar to two sum. keep everything in a map and find it then at O(1); let each pair(A,B) be A = some [0->59] value to represent the x % 60, B = the counting of such numbers that has appeared so far. the idea is to then iterate thoough the input, for each N, find its complement that makes it % 60, and add the number of the complements seen to the ans.
    int numPairsDivisibleBy60(vector<int>& time) {
        unordered_map<int,int> seen{};
        int ans = 0;
        for(const auto&n: time){
            int target = (n == 0) ? 0:(60- n % 60) % 60;
            auto ite = seen.find(target);
            if (ite != seen.end()){
                ans+=ite->second;
            }
            seen[n%60]+=1;
        }
        return ans;
    }
};