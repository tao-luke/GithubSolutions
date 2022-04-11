class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        // consider 2 oceans one by one. traverse as far as possible for each ocean. and the answers are the ones travelled to by both ocean traversal. O(mxn)
        map<pair<int,int>,int> visited{};
        
        dfs_mark(make_pair(0,0), make_pair(0,0), heights, visited);
        dfs_mark(make_pair(heights.size()-1,0), make_pair(0,heights[0].size()-1), heights, visited);
        vector<vector<int>> ans{};
        for(const auto& p: visited){
            if (p.second == 2) ans.push_back(vector<int>{p.first.first,p.first.second});
        }
        return ans;
    }
    void dfs_mark(pair<int,int> a, pair<int,int> b, vector<vector<int>>& heights, map<pair<int,int>,int>& history){
        set<pair<int,int>> visited{};
        for(int i = a.second; i < heights[0].size();i++){
            dfs(a.first, i,visited,history, heights);
        }
        for(int i = b.first; i < heights.size(); i++){
            dfs(i, b.second, visited, history, heights);
        }
    }
    void dfs(int i , int j, set<pair<int,int>>& visited, map<pair<int,int>,int>& history,vector<vector<int>>& heights){
        if (visited.find(make_pair(i,j)) != visited.end()) return;
        visited.insert(make_pair(i,j));
        history[make_pair(i,j)]++;
        int currH = heights[i][j];
        if (i-1 >= 0 && heights[i-1][j] >= currH) dfs(i-1,j,visited,history, heights);
        if (i+1 < heights.size() && heights[i+1][j] >= currH) dfs(i+1,j,visited,history, heights);
        if (j-1 >= 0 && heights[i][j-1] >= currH) dfs(i,j-1,visited,history, heights);
        if (j+1 < heights[0].size() && heights[i][j+1] >= currH) dfs(i,j+1,visited,history, heights);
    }
};