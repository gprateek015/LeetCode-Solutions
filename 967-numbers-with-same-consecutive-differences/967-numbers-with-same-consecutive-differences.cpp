class Solution {
    set<int> st;
    void helper(int n, int i, int k, int x, string s) {
        if(i>=n) {
            st.insert(stoi(s));
            return;
        }
        if(x-k>=0) 
            helper(n, i+1, k, x-k, s+to_string(x));
        if(x+k<=9)
            helper(n, i+1, k, x+k, s+to_string(x));
    }
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        for(int i=1; i<=9; i++) {
            helper(n, 0, k, i, "");
        }
        vector<int> ans;
        for(auto i: st) 
            ans.push_back(i);
        return ans;
    }
};