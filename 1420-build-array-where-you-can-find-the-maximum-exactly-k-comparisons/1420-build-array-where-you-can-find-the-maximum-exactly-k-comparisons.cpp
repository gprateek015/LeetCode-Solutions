class Solution {
public:
    int numOfArrays(int n, int m, int k) {
        const int mod = 1e9 + 7;
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(m + 2, vector<int>(k + 1, -1)));
        
        function<int(int, int, int)> getWays = [&](int index, int prevMax, int cost) {
            
            if(cost > k) {
                return 0;
            }

            if(index == n) {
                return (int)(cost == k);
            }

            if(dp[index][prevMax + 1][cost] != -1) {
                return dp[index][prevMax + 1][cost];
            }

            int ways = 0;

            for(int element = 1; element <= m; element++) {
                if(element > prevMax) { 
                    ways = (ways + getWays(index + 1, element, cost + 1)) % mod;
                }
                else {
                    ways = (ways + getWays(index + 1, prevMax, cost)) % mod;
                }
            }
            return dp[index][prevMax + 1][cost] = ways;
        };

        return getWays(0, -1, 0);
    }
};