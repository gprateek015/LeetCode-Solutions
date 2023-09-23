bool cmp(string &s1, string &s2) {
    return s1.size()<s2.size();
}
class Solution {
    vector<int> dp;
    bool check(string &str1, string &str2, int i=0, int j=0,  bool flag=0) {
        if(str2.size() - str1.size() != 1) return false;
        while(i<str1.size() and str1[i]==str2[j]) {
            i++; j++;
        }
        if(i==str1.size())
            return true;
        if(flag==0)
            return check(str1, str2, i, j+1, 1);
        return false;
    }
    int helper(vector<string>& words, int i=0) {
        if(i>=words.size()) 
            return 0;
        if(dp[i] != -1) 
            return dp[i];
        int ans=0;
        for(int j=i+1; j<words.size(); j++) {
            if(check(words[i], words[j])) {
                ans = max(ans, helper(words, j));
            }
        }
        return dp[i] = 1+ans;
    }
public:
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), cmp);
        dp = vector<int>(words.size()+1, -1);
        int ans = 0;
        for(int i=0; i<words.size(); i++) {
            ans = max(ans, helper(words, i));
        }
        // for(int i=0; i<words.size(); i++) {
        //     cout << words[i] << ' ' << dp[i] << endl;
        // }
        return ans;
    }
};