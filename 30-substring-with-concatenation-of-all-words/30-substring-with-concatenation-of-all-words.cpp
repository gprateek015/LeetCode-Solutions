class Solution {
    bool check(unordered_map<string, int> mp, string s, int len) {
        for(int i=0; i<s.size(); i+=len) {
            string t = s.substr(i, len);
            if(mp.find(t) != mp.end()) {
                mp[t]--;
                if(mp[t] < 0) 
                    return false;
            } else 
                return false;
        }
        return true;
    }
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int x = words[0].size()*words.size();
        unordered_map<string, int> mp;
        for(int i=0; i<words.size(); i++) 
            mp[words[i]]++;
        vector<int> t;
        for(int i=0; i+x<=s.size(); i++)  {
            if(check(mp, s.substr(i, x), words[0].size())) {
                t.push_back(i);
            }
        }
        return t;
    }
};