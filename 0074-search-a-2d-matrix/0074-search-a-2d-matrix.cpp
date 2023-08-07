class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r = 0;
        int s=0, end=matrix.size()-1;
        while(s<=end) {
            int m = (s+end)/2;
            if(matrix[m][0] <= target) {
                r = m;
                s = m+1;
            } else {
                end = m-1;
            } 
        }
        if(r<0) return false;
        return binary_search(matrix[r].begin(), matrix[r].end(), target);
    }
};