class Solution {
    bool helper(vector<vector<int>>& mat, int i, int j) {
        while(i<mat.size() && j<mat[0].size()) {
            if(i==0 || j==0) {
                i++;
                j++;
            } else {
                if(mat[i][j]!=mat[i-1][j-1])
                    return false;
                i++;
                j++;
            }
        }
        return true;
    }
public:
    bool isToeplitzMatrix(vector<vector<int>>& mat) {
        for(int i=0; i<mat.size(); i++) {
            if(!helper(mat, i, 0)) 
                return false;
        }
        for(int j=0; j<mat[0].size(); j++) {
            if(!helper(mat, 0, j)) 
                return false;
        }
        return true;
    }
};