class Solution {
public:
    
    void explore(vector<vector<char>>& grid,int i, int j,bool seen[][300]){
        seen[i][j] = true;
        
        if ((i-1 >= 0) && (grid[i-1][j] == '1') && (!seen[i-1][j])) explore(grid,i-1,j,seen);
        if ((i+1 < grid.size()) && (grid[i+1][j] == '1') && (!seen[i+1][j])) explore(grid,i+1,j,seen);
        if (j-1 >= 0 && grid[i][j-1] == '1' && !seen[i][j-1]) explore(grid,i,j-1,seen);
        if (j+1 < grid[0].size() && grid[i][j+1] == '1' && !seen[i][j+1]) explore(grid,i,j+1,seen);
    }
    int numIslands(vector<vector<char>>& grid) {
        //set all as 0
        bool seen[grid.size()][300];
        memset(seen,0,sizeof(seen));
        
        int result = 0;
        for(int i = 0; i < grid.size();i++){
            for(int j = 0; j < grid[0].size();j++){
                if (seen[i][j] == false && grid[i][j] == '1'){ //not explored and IS island
                    explore(grid,i,j,seen);
                    result++;
                }
            }
        }
        return result;
    }
};