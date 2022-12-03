class Solution {
public:
    string frequencySort(string s) {
        map<char, int> mp;
        for(char c: s) {
            mp[c]++;
        }
        vector<pair<int, char>> v;
        for(auto i: mp) {
            v.push_back({i.second, i.first});
        }
        sort(v.rbegin(), v.rend());
        string ans = "";
        for(int i=0; i<v.size(); i++) {
            ans += string(v[i].first, v[i].second);
        }
        return ans;
    }
};