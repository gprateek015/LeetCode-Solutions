class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n, 0));
        int l=0;
        int num = 1;
        while(l<n) {
            for(int i=0+l; i<n-l; i++)
                ans[l][i] = num++;;
            for(int i=l+1; i<n-l; i++)
                ans[i][n-l-1] = num++;
            for(int i=n-l-2; i>=0+l; i--)
                ans[n-l-1][i] = num++;
            for(int i=n-l-2; i>=0+l+1; i--)
                ans[i][l] = num++;
            l++;
        }
        return ans;
    }
};