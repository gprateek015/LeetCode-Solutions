bool cmp(vector<int> &a, vector<int> &b) {
    return a[0] < b[0];
}
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);
        vector<vector<int>> ans;
        int st = intervals[0][0], end = intervals[0][1];
        for(auto &it: intervals) {
            if(it[0] <= end) {
                end = max(end, it[1]);
            } else {
                ans.push_back({st, end});
                st = it[0];
                end = it[1];
            }
        }
        ans.push_back({st, end});
        return ans;
    }
};