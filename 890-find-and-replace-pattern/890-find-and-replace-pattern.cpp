bool isValid(string pattern, string word) {
    if(pattern.length()!=word.length())
        return false;
    map<char, char> m;
    map<char, char> n;
    bool res = true;
    for(int i=0; i<pattern.length(); i++) {
        if(m.find(pattern[i])==m.end() && n.find(word[i])==n.end()){
            m[pattern[i]] = word[i];
            n[word[i]] = pattern[i];
        }
        if(m[pattern[i]] != word[i] || n[word[i]!=pattern[i]]) {
            res=false; break;
        };
    }
    return res;
}
class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;
        for(int i=0; i<words.size(); i++) {
            if(isValid(pattern, words[i])) {
                ans.push_back(words[i]);
            }
        }
        return ans;
    }
};