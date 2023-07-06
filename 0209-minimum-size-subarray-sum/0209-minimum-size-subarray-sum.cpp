class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int ans = 1e6, sum = 0;
        int i=0, j=0;
        while(j<nums.size()) {
            while(sum<target && j<nums.size()) {
                sum += nums[j++];
                if(sum>=target)
                    ans = min(ans, j-i);
            }
            
            while(sum>=target && i<j) {
                sum -= nums[i++];
                if(sum>=target)
                    ans = min(ans, j-i);
            }
        }
        return ans==1e6 ? 0 : ans;
    }
};