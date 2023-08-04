class Solution {
    vector<int> dp;
    bool helper(string &s, int i, vector<string>& wordDict) {
        if(i>=s.size()) {
            return true;
        }
        if(dp[i]!=-1)
            return dp[i];
        for(string &str: wordDict) {
            if(str.compare(s.substr(i, str.size()))==0) {
                if(helper(s, i+str.size(), wordDict)) {
                    return dp[i]=true;
                }
            }
        }
        return dp[i]=false;
    }
public:
    bool wordBreak(string &s, vector<string>& wordDict) {
        dp = vector<int>(s.size()+1, -1);
        return helper(s, 0, wordDict);
    }
};