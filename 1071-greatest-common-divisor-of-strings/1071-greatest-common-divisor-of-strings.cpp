class Solution {
    bool check(string &s, int len) {
        if(!len) return 1;
        for(int i=0; i<s.size(); i+=len) {
            if(s.substr(i, len).compare(s.substr(0, len)) != 0) {
                return 0;
            }
        }
        return 1;
    }
public:
    string gcdOfStrings(string str1, string str2) {
        set<string> st;
        string ans = "";
        for(int i=0; i<=str1.size(); i++) {
            if(check(str1, i)) {
                st.insert(str1.substr(0, i));
            }
        }
        for(int i=0; i<=str2.size(); i++) {
            if(check(str2, i) && st.find(str2.substr(0, i)) != st.end()) {
                ans = str2.substr(0, i);
            }
        }
        return ans;
    }
};