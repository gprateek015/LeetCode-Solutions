class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> arr({".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."});
        set<string> st;
        for(auto &word: words) {
            string str = "";
            for(auto &c: word) {
                str += arr[c-'a'];
            }
            st.insert(str);
        }
        return st.size();
    }
};