class Solution {
    int area(vector<vector<int>> &grid, int i, int j, vector<vector<bool>> &visited) {
        if(i<0||i>=grid.size()||j<0||j>=grid[0].size())
            return 0;
        if(visited[i][j])
            return 0;
        if(!grid[i][j])
            return 0;
        visited[i][j]=1;
        int ans = 1;
        ans += area(grid, i, j-1, visited);
        ans += area(grid, i, j+1, visited);
        ans += area(grid, i-1, j, visited);
        ans += area(grid, i+1, j, visited);
        return ans;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), 0));
        int ans=0;
        for(int i=0; i<grid.size(); i++) {
            for(int j=0; j<grid[0].size(); j++) {
                if(grid[i][j] && !visited[i][j]) {
                    ans = max(ans, area(grid, i, j, visited));
                }
            }
        }
        return ans;
    }
};