class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.size()==1)
            return nums[0];
        int curr_min=nums[0], curr_max=nums[0], global_max=nums[0];
        for(int i=1; i<nums.size(); i++) {
            if(nums[i]<0) {
                int t = curr_min;
                curr_min = min(curr_max*nums[i], nums[i]);
                curr_max = max(nums[i], t*nums[i]);
            } else if(nums[i]>0) {
                curr_min = min(curr_min*nums[i], nums[i]);
                curr_max = max(curr_max*nums[i], nums[i]);
            } else {
                curr_min = 0;
                curr_max = 0;
            }
            global_max = max(global_max, curr_max);
        }
        return global_max;
    }
};