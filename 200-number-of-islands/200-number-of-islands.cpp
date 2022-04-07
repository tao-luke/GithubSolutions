class Solution {
public:
    int visit(vector<vector<char>>& grid, int i, int j){
        if (grid[i][j] == '0') return 0;
        grid[i][j] = '0';
        if (i-1 >= 0) visit(grid,i-1,j);
        if (j-1 >= 0) visit(grid,i,j-1);
        if (j+1 < grid[0].size()) visit(grid,i,j+1);
        if (i+1 < grid.size()) visit(grid,i+1,j);
        return 1;
    }
    int numIslands(vector<vector<char>>& grid) {
        int result = 0;
        for(int i = 0; i < grid.size();i++){
            for(int j = 0; j < grid[0].size(); j++){
                result+=visit(grid,i,j);
            }
        }
        return result;
    }
};