class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        unordered_map<char, int> mp;
        for(auto &str: words2) {
            unordered_map<char,int> m;
            for(auto &c: str) {
                m[c]++;
            }
            for(auto &it: m) {
                mp[it.first] = max(it.second, mp[it.first]);
            }
        }
        vector<string> ans;
        for(auto &str: words1) {
            unordered_map<char, int> m;
            for(auto &c: str) {
                m[c]++;
            }
            bool flag=1;
            for(auto &it: mp) {
                if(m[it.first] < it.second) {
                    flag = 0;
                    break;
                }
            }
            if(flag) 
                ans.push_back(str);
        }
        return ans;
    }
};