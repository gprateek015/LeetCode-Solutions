bool check(string &str1, string &str2) {
    for(int i=0; i<str1.size(); i++) {
        if(str1[i]=='.') continue;
        if(str1[i]!=str2[i])
            return false;
    }
    return true;
}
class WordDictionary {
    unordered_map<int, vector<string>> mp;
public:
    WordDictionary() {
        
    }
    
    void addWord(string word) {
        mp[word.size()].push_back(word);
    }
    
    bool search(string word) {
        for(auto &x: mp[word.size()]) {
            if(check(word, x)) {
                return true;
            }
        }
        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */