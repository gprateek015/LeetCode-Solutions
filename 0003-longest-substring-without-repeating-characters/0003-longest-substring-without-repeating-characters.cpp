class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, int> mp;
        int i=0, j=0, ans=0;
        while(i<s.size()) {
            if(mp.count(s[i])) j = max(j, mp[s[i]]+1);
            mp[s[i]] = i;
            ans = max(ans, i-j+1);
            i++;
        }
        return ans;
    }
};