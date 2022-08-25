class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        map<char, int> mp;
        for(char c: magazine) {
            mp[c]++;
        }
        for(char c: ransomNote) {
            if(mp.find(c)!=mp.end()) {
                mp[c]--;
            } else 
                return 0;
            if(mp[c] < 0) 
                return 0;
        }
        return 1;
    }
};