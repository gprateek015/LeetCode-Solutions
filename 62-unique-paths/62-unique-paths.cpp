class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> arr(m, vector<int>(n, 0));
        arr[m-1][n-1] = 0;
        for(int i=m-1; i>=0; i--) {
            for(int j=n-1; j>=0; j--) {
                if(i==m-1) {
                    arr[i][j] = 1;
                } else if(j==n-1) {
                    arr[i][j] = 1;
                } else {
                    arr[i][j] = arr[i+1][j] + arr[i][j+1];
                }
            }
        }
        return arr[0][0];
    }
};