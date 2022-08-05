class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<unsigned int> dp(target+1, 0);
        sort(nums.begin(), nums.end()); 
        for(int i=1; i<=target; i++) {
            dp[i] = binary_search(nums.begin(), nums.end(), i);
            for(int j=0; j<nums.size(); j++) {
                if(i > nums[j])
                    dp[i] += dp[i-nums[j]];
                else break;
            }
        }
        return dp[target];
    }
};