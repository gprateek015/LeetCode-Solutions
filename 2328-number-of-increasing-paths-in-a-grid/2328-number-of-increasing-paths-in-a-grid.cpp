class Solution {
    int m = 1e9+7;
    vector<vector<long long>> dp;
    int helper(vector<vector<int>>& grid, int i, int j) {
        long long ans = 1;
        if(dp[i][j]!=-1) 
            return dp[i][j];
        if(i+1 < grid.size() && grid[i+1][j]>grid[i][j]) {
            ans = (ans + helper(grid, i+1, j))%m;
        }
        if(i-1 >= 0 && grid[i-1][j]>grid[i][j]) {
            ans = (ans + helper(grid, i-1, j))%m;
        }
        if(j+1 < grid[0].size() && grid[i][j+1]>grid[i][j]) {
            ans = (ans + helper(grid, i, j+1))%m;
        }
        if(j-1 >= 0 && grid[i][j-1]>grid[i][j]) {
            ans = (ans + helper(grid, i, j-1))%m;
        }
        return dp[i][j] = ans;
    }
public:
    int countPaths(vector<vector<int>>& grid) {
        long long ans=0;
        dp = vector<vector<long long>>(grid.size(), vector<long long>(grid[0].size(), -1));
        for(int i=0; i<grid.size(); i++) {
            for(int j=0; j<grid[0].size(); j++) {
                ans = (ans + helper(grid, i, j))%m;
            }
        }
        return (ans+m)%m;
    }
};