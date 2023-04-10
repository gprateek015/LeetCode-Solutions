class Solution {
    bool check(char a, char b) {
        if(a=='(' && b==')') return true;
        if(a=='{' && b=='}') return true;
        if(a=='[' && b==']') return true;
        return false;
    }
public:
    bool isValid(string s) {
        stack<char> st;
        for(char c: s) {
            if(!st.empty() && check(st.top(), c)) {
                st.pop();
                continue;
            }
            st.push(c);
        }
        return st.empty();
    }
};