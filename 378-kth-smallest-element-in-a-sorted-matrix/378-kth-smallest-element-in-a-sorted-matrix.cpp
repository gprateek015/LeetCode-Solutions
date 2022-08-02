class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int> pq;
        for(auto &i: matrix) {
            for(auto &j: i) {
                pq.push(j);
            }
        }
        k = matrix.size()*matrix[0].size() - k;
        while(k--) {
            pq.pop();
        }
        return pq.top();
    }
};