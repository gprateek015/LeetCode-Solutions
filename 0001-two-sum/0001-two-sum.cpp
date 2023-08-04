class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for(int i=0; i<nums.size(); i++) {
            int j = find(nums.begin(), nums.end(), target-nums[i]) - nums.begin();
            if(j<nums.size() && i!=j) {
                return {i, j};
            }
        }
        return {};
    }
};