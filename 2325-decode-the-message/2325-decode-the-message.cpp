class Solution {
public:
    string decodeMessage(string key, string message) {
        map<char, char> mp;
        int i=0;
        for(char c: key) {
            if(c!=' ' and mp.find(c)==mp.end()) {
                mp[c] = i+'a';
                i++;
            }
        }
        string ans="";
        for(char a: message) {
            if(a == ' ') {
                ans += ' ';
                continue;
            }
            ans += mp[a];
        }
        return ans;
    }
};