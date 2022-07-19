class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if(numRows==1) {
            vector<vector<int>> t(1, vector<int>(1,1));
            return t;
        }
        vector<vector<int>> temp = generate(numRows-1);
        int n = temp[temp.size()-1].size();
        vector<int> t(n+1);
        t[0]=1, t[n]=1;
        for(int i=1; i<n; i++) {
            int a = temp[temp.size()-1][i-1], b = temp[temp.size()-1][i];
            t[i] = a+b;
        }
        temp.push_back(t);
        return temp;
    }
};