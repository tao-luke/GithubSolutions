class Solution {
public:
    void visit(const vector<vector<int>>& isConnected, unordered_set<int>& seen, int i){
        if (seen.count(i) != 0) return;
        seen.insert(i);
        for(int j = 0; j < isConnected.size();j++){
            if (isConnected[i][j] == 1) visit(isConnected,seen,j);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        unordered_set<int> seen{};
        int result = 0;
        for(int i = 0; i < isConnected.size();i++){
            if (seen.count(i) == 0) result++;
            visit(isConnected,seen,i);
        }
        return result;
    }
};