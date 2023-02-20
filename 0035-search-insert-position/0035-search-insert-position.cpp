class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        // return lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        // or
        int s=0, e=nums.size()-1;
        int ans=e+1;
        while(s<=e) {
            int m = e - (e-s)/2;
            if(nums[m] == target) 
                return m;
            else if(nums[m]>target) {
                ans = m;
                e = m-1;
            } else 
                s = m+1;
        }
        return ans;
    }
};