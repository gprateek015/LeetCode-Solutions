class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1, 0);
        int p = 0;
        for(int i=1; i<=n; i++) {
            if((i & (i-1)) == 0) {
                ans[i] = 1;
                p = i;
            } else {
                ans[i] = ans[p] + ans[i-p];
            }
        }
        return ans;
    }
};