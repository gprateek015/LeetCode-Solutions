class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        nums.erase(unique(nums.begin(), nums.end()), nums.end());
        int ans=0, i=0;
        while(i<nums.size()) {
            int curr = 0, t=i;
            while(t+1<nums.size() && nums[t]+1==nums[t+1]) {
                t++;
            }
            ans = max(ans, t-i+1);
            i=t;
            i++;
        }
        return ans;
    }
};