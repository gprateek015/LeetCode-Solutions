class Solution {
    long long helper(vector<vector<int>>& ques, int i, vector<long long> &dp) {
        if(i>=ques.size())
            return 0;
        if(dp[i]!=-1)
            return dp[i];
        long long ans = ques[i][0] + helper(ques, i+ques[i][1]+1, dp);
        ans = max(ans, helper(ques, i+1, dp));
        return dp[i] = ans;
    }
public:
    long long mostPoints(vector<vector<int>>& questions) {
        vector<long long> dp(questions.size(), -1);
        return helper(questions, 0, dp);
    }
};