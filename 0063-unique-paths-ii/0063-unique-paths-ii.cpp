class Solution {
    vector<vector<int>> dp;
public:
    Solution() {
        dp = vector<vector<int>>(101, vector<int>(101, -1));
    }
    int uniquePathsWithObstacles(vector<vector<int>>& grid, int i=0, int j=0) {
        if(i>=grid.size() || j>=grid[0].size()) return 0;
        if(grid[i][j] == 1) return 0;
        if(i==grid.size()-1 && j==grid[0].size()-1) return 1;
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        int ans = uniquePathsWithObstacles(grid, i+1, j);
        ans += uniquePathsWithObstacles(grid, i, j+1);
        return dp[i][j] = ans;
    }
};