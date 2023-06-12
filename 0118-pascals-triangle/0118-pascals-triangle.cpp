class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if(numRows==1) return {{1}};
        
        vector<vector<int>> sm = generate(numRows-1);
        vector<int> *lastRow = &sm.back();
        vector<int> newRow(lastRow->size()+1, 1);
        for(int i=1; i<lastRow->size(); i++) {
            newRow[i] = lastRow->at(i) + lastRow->at(i-1);
        }
        sm.push_back(newRow);
        return sm;
    }
};