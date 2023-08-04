class Solution {
    unordered_set<string> st;
    vector<int> dp;
    bool helper(string &s, int i) {
        if(i>=s.size()) {
            return true;
        }
        if(dp[i]!=-1)
            return dp[i];
        for(int len=1; i+len<=s.size(); len++) {
            if(st.find(s.substr(i, len))!=st.end()) {
                if(helper(s, i+len)) {
                    return dp[i]=true;
                }
            }
        }
        return dp[i]=false;
    }
public:
    bool wordBreak(string &s, vector<string>& wordDict) {
        for(auto str: wordDict) {
            st.insert(str);
        }
        dp = vector<int>(s.size()+1, -1);
        return helper(s, 0);
    }
};