class Solution {
    vector<string> split(string s, char c) {
        stringstream ss(s);
        string t;
        vector<string> ans;
        while(getline(ss, t, c)) {
            if(t.size()) {
                ans.push_back(t);
            }
        }
        return ans;
    }
public:
    string reverseWords(string s) {
        vector<string> strs = split(s, ' ');
        reverse(strs.begin(), strs.end());
        string ans = "";
        for(int i=0; i<strs.size(); i++) {
            ans += strs[i];
            if(i!=strs.size()-1) {
                ans += " ";
            }
        }
        return ans;
    }
};