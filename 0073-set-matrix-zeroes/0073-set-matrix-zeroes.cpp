class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<int> r, c;
        for(int i=0; i<matrix.size(); i++) {
            for(int j=0; j<matrix[0].size(); j++) {
                if(matrix[i][j]==0) {
                    r.push_back(i);
                }
            }
        }
        for(int i=0; i<matrix[0].size(); i++) {
            for(int j=0; j<matrix.size(); j++) {
                if(matrix[j][i]==0) {
                    c.push_back(i);
                }
            }
        }
        for(int i=0; i<matrix.size(); i++) {
            bool flag_r = binary_search(r.begin(), r.end(), i);
            for(int j=0; j<matrix[0].size(); j++) {
                if(flag_r) 
                    matrix[i][j] = 0;
                else {
                    bool flag_c = binary_search(c.begin(), c.end(), j);
                    if(flag_c)
                        matrix[i][j] = 0;
                }
            }
        }
    }
};