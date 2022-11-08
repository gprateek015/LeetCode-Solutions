class Solution {
public:
    string makeGood(string s) {
        if(s.size()==0) 
            return "";
        // cout << char('a' - 'A' + 'B');
        for(int i=0; i<int(s.size())-1; i++) {
            if(abs(s[i]-s[i+1]) == 32) {
                string str = s.substr(0, i) + s.substr(i+2);
                return makeGood(str);
            }
        }
        return s;
    }
};