class Solution {
public:
    bool detectCapitalUse(string word) {
        if(word.size() == 1) return 1;
        if(word[0]>='a' && word[0]<='z') {
            for(int i=1; i<word.size(); i++) {
                if(!(word[i]>='a' && word[i]<='z')) return 0;
            }
            return 1;
        } else {
            bool flag = 1;
            for(int i=1; i<word.size(); i++) {
                if(!(word[i]>='a' && word[i]<='z')) flag = 0;
            }
            if(flag) return 1;
            flag = 1;
            for(int i=1; i<word.size(); i++) {
                if(!(word[i]>='A' && word[i]<='Z')) flag = 0;
            }
            return flag;
        }
        return 0;
    }
};