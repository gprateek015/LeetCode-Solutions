class Solution {
public:
    int mod = 1e9+7;
    int numRollsToTarget(int n, int k, int target) {
        
        int dp[n+1][target+1];
        memset(dp, 0, sizeof dp);
        dp[n][0] = 1;
        vector<int> prefixSum(max(k,target)+1, 0);
        for(int i=1; i<=target; i++){
            prefixSum[i] += prefixSum[i-1];
            prefixSum[i] %= mod;
            if(i<=k){
                prefixSum[i]++;
                dp[n-1][i] = 1;
            }
            prefixSum[i] %= mod;
        }
        
        for(int i=n-2; i>=0; i--){
            vector<int> currentPrefixSum = {0};
            for(int j=1; j<target+1; j++){
                int start = max(j-k-1, 0);
                int end  = j-1;
                dp[i][j] += (mod + prefixSum[end] - prefixSum[start])%mod;
                dp[i][j] %= mod;    
                currentPrefixSum.push_back((currentPrefixSum.back()+dp[i][j])%mod);
            }
            prefixSum = currentPrefixSum;
        }
        
        return dp[0][target];
    }
};