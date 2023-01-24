class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> arr(n+1, 0);
        set<int> st;
        for(auto it: trust) {
            arr[it[1]]++;
            st.insert(it[0]);
        }
        for(int i=1; i<=n; i++) {
            if(arr[i] == n-1 && st.find(i)==st.end()) {
                return i;
            }
        }
        return -1;
    }
};