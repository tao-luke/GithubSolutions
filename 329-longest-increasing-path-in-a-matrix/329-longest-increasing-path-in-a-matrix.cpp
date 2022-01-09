class Solution {
public:
    void attempt(stack<pair<int,int>>& hist, const vector<vector<int>>& matrix, int i, int j, int current) {
        if (i < 0 || j < 0|| i >= matrix.size()||j >= matrix[0].size()) return;
        if (matrix[i][j] > current) {
            hist.push(make_pair(i, j));
        }
    }
    bool isVisited(const vector<vector<int>>& dp, const vector<vector<int>>& matrix  ,int i, int j, int current){
        if (i < 0 or j < 0 or i >= matrix.size() or j >= matrix[0].size()) return true;
        if (matrix[i][j] <= current) return true;
        if (dp[i][j] == 0) return false;
        return true;
    }
    bool isValid(const vector<vector<int>>& matrix,int i, int j) {
        if (i < 0 or j < 0 or i >= matrix.size() or j >= matrix[0].size()) return false;
        return true;
    }
    int bestAround(const vector<vector<int>>& matrix, const vector<vector<int>>& dp, int i, int j){
        int best = dp[i][j];
        if (isValid(matrix, i-1, j) && matrix[i-1][j] > matrix[i][j]) best = max(dp[i-1][j] + 1, best);
        if (isValid(matrix, i, j-1) && matrix[i][j-1] > matrix[i][j]) best = max(dp[i][j-1] + 1, best);
        if (isValid(matrix, i, j+1) && matrix[i][j+1] > matrix[i][j]) best = max(dp[i][j+1] + 1, best);
        if (isValid(matrix, i+1, j) && matrix[i+1][j] > matrix[i][j]) best = max(dp[i+1][j] + 1, best);
        return best;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        vector<vector<int>>dp(matrix.size(), vector<int>(matrix[0].size(),0));
        stack<pair<int,int>> hist{};
        for(int i = 0; i < matrix.size(); i++) {
            for(int j = 0; j < matrix[0].size();j++) {
                hist.push(make_pair(i, j));
            }
        }
        int best = 0;
        while(!hist.empty()) {
            int i = hist.top().first;
            int j = hist.top().second;
            // cout << i << " " << j << endl;
            if (isVisited(dp, matrix, i-1, j, matrix[i][j]) and isVisited(dp, matrix, i, j-1, matrix[i][j]) and isVisited(dp, matrix, i, j+1,matrix[i][j]) and isVisited(dp, matrix, i+1, j, matrix[i][j])) { // if everything around is full visited, we can do this easy.

                dp[i][j] = max(bestAround(matrix, dp, i, j), 1);
                hist.pop();
                best = max(best,dp[i][j]);
                // cout << " hello " << dp[i][j]<< endl;
                continue;
            }
            
            dp[i][j] = 1;
            
            attempt(hist, matrix, i-1, j, matrix[i][j]);
            attempt(hist, matrix, i, j-1, matrix[i][j]);
            attempt(hist, matrix, i, j+1, matrix[i][j]);
            attempt(hist, matrix, i+1, j, matrix[i][j]);
        }
        return best;
    }
};