class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        set<int> r, c;
        for(int i=0; i<matrix.size(); i++) {
            for(int j=0; j<matrix[0].size(); j++) {
                if(matrix[i][j]==0) {
                    r.insert(i);
                    c.insert(j);
                }
            }
        }
        for(int i=0; i<matrix.size(); i++) {
            bool flag_r = r.find(i)!=r.end();
            for(int j=0; j<matrix[0].size(); j++) {
                if(flag_r) 
                    matrix[i][j] = 0;
                else {
                    bool flag_c = c.find(j) != c.end();
                    if(flag_c)
                        matrix[i][j] = 0;
                }
            }
        }
    }
};