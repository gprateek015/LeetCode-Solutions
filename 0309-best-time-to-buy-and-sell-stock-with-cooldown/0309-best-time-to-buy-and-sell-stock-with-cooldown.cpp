class Solution {
    vector<vector<int>> dp;
    int helper(vector<int> &prices, int st, int cur) {
        if(cur >= prices.size())
            return 0;
        if(dp[st][cur]!=-1)
            return dp[st][cur];
        int a = helper(prices, st, cur+1);
        a = max(a, helper(prices, cur, cur+1));
        a = max(a, prices[cur]-prices[st]+helper(prices, cur+2, cur+2));
        return dp[st][cur] = a;
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        dp = vector<vector<int>>(n, vector<int>(n, -1));
        return helper(prices, 0, 1);
    }
};