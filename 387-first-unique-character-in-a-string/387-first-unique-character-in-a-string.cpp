class Solution {
public:
    int firstUniqChar(string s) {
        map<char, int> mp;
        for(int i=0; i<s.size(); i++) {
            if(mp.find(s[i])!=mp.end()) 
                mp[s[i]] = 1e9;
            else
                mp[s[i]] = i;
        }
        int ans=1e9;
        for(auto it: mp) {
            ans = min(ans, it.second);
        }
        return ans==1e9 ? -1 : ans;
    }
};