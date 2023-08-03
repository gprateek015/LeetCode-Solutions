class Solution {
    void solve(string &digits, int i, vector<string> &mp, vector<string> &ans, string curr) {
        if(i>=digits.size()) {
            if(curr.size())
                ans.push_back(curr);
            return;
        }
        for(char c: mp[digits[i]-'0'-2]) {
            solve(digits, i+1, mp, ans, curr+c);
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string> mp({"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"});
        vector<string> ans;
        solve(digits, 0, mp, ans, "");
        return ans;
    }
};