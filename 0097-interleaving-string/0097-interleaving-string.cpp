class Solution {
    vector<vector<int>> dp;
public:
    Solution() {
        dp = vector<vector<int>> (101, vector<int>(101, -1));
    }
    bool isInterleave(string &s1, string &s2, string &s3, int i=0, int j=0, int k=0) {
        int n=s1.size(), m=s2.size();
        if(i>=n and j>=m) {
            if(k>=s3.size())
                return true;
            else 
                return false;
        }
        if(k>=s3.size())
            return false;
        if(dp[i][j] != -1) {
            return dp[i][j];
        }
        bool ans = 0;
        if(s1[i]==s3[k]) {
            ans |= isInterleave(s1, s2, s3, i+1, j, k+1);
        }
        if(s2[j]==s3[k]) {
            ans |= isInterleave(s1, s2, s3, i, j+1, k+1);
        }
        return dp[i][j] = ans;
    }
};