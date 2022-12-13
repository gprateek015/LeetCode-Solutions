class Solution {
    vector<vector<int>> dp;
    int helper(vector<vector<int>>& matrix, int r, int c) {
        if(r>=matrix.size())
            return 0;
        if(c<0 || c>=matrix[0].size()) 
            return 100000;
        if(dp[r][c]!=-1)
            return dp[r][c];
        int ans = helper(matrix, r+1, c-1);
        ans = min(ans, helper(matrix, r+1, c));
        ans = min(ans, helper(matrix, r+1, c+1));
        return dp[r][c] = ans + matrix[r][c];
    }
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        dp = vector<vector<int>>(matrix.size(), vector<int>(matrix[0].size(), -1));
        int ans=1e5;
        for(int i=0; i<matrix.size(); i++) {
            ans = min(ans, helper(matrix, 0, i));
        }
        return ans;
    }
};