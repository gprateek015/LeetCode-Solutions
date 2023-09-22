class Solution {
public:
    bool isSubsequence(string &s, string &t, int i=0, int j=0) {
        if(i==s.size()) return 1;
        if(j==t.size()) return 0;
        if(s[i] == t[j]) 
            return isSubsequence(s, t, i+1, j+1);
        return isSubsequence(s, t, i, j+1);
    }
};