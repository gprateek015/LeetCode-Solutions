class Solution {
    void solve(vector<vector<int>>& mat, int i, int j) {
        int n=mat.size(), m=mat[0].size();
        vector<int> temp;
        int x=i, y=j;
        while(i<n && j<m) {
            temp.push_back(mat[i++][j++]);
        }
        sort(temp.begin(), temp.end());
        i=x; j=y;
        x=0;
        while(i<n && j<m) {
            mat[i++][j++] = temp[x++];
        }
    }
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        for(int i=0; i<mat.size(); i++) 
            solve(mat, i, 0);
        for(int i=0; i<mat[0].size(); i++) 
            solve(mat, 0, i);
        return mat;
    }
};