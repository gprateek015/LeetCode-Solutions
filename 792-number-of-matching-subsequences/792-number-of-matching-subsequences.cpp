class Solution {
    bool check(unordered_map<char, vector<int>> &mp, string &str) {
        int prev = -1;
        for(char c: str) {
            if(mp.find(c)!=mp.end()) {
                auto it = upper_bound(mp[c].begin(), mp[c].end(), prev);
                if(it!=mp[c].end()) {
                    prev = *it;
                } else {
                    return false;
                }
            } else {
                return false;
            }
        }
        return true;
    }
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        unordered_map<char, vector<int>> mp;
        for(int i=0; i<s.size(); i++) {
            mp[s[i]].push_back(i);
        }
        int count = 0;
        for(auto &str: words) {
            count += check(mp, str);
        }
        return count;
    }
};