class Solution {
    
public:
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.size()<2) 
            return nums.size();
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(2, 1));
        for(int i=0; i<n; i++) {
            for(int j=i-1; j>=0; j--) {
                if(nums[i]>nums[j])
                    dp[i][0] = max(dp[i][0], dp[j][1]+1);
            }
            for(int j=i-1; j>=0; j--) {
                if(nums[i]<nums[j])
                    dp[i][1] = max(dp[i][1], dp[j][0]+1);
            }
        }
        int ans=1;
        for(int i=0; i<n; i++) {
            ans = max({ans, dp[i][0], dp[i][1]});
        }
        return ans;
    }
};