class Solution {
    vector<vector<vector<int>>> dp;
    
    int solve(int k, vector<int>& prices, int i, int flag) {
        if(i>=prices.size()) 
            return 0;
        if(k<=0) 
            return 0;
        if(dp[i][flag][k]!=-1)
            return dp[i][flag][k];
        int op = solve(k, prices, i+1, flag);
        if(flag==0) {
            op = max(op, -prices[i]+solve(k, prices, i+1, 1));
        } else {
            op = max(op, prices[i]+solve(k-1, prices, i+1, 0));
        }
        return dp[i][flag][k] = op;
    }
public:
    int maxProfit(int k, vector<int>& prices) {
        dp = vector<vector<vector<int>>>(1000, vector<vector<int>>(2, vector<int>(101, -1)));
        return solve(k, prices, 0, 0);
    }
};