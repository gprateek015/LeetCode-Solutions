class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<vector<int>> arr(n, vector<int>(0));
        for(auto &i: roads) {
            arr[i[0]].push_back(i[1]);
            arr[i[1]].push_back(i[0]);
        }
        int ans = 0;
        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) {
                int curr = arr[i].size() + arr[j].size();
                if(find(arr[i].begin(), arr[i].end(), j) != arr[i].end()) {
                    curr--;
                }
                ans = max(ans, curr);
            }
        }
        return ans;
    }
};