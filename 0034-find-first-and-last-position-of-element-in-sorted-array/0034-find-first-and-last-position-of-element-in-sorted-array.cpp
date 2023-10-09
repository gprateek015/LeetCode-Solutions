class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        auto it_lower = lower_bound(nums.begin(), nums.end(), target);
        auto it_upper = upper_bound(nums.begin(), nums.end(), target);
        if(it_lower == it_upper) {
            return {-1, -1};
        }
        int a = it_lower-nums.begin();
        int b = it_upper-nums.begin()-1;
        return {a,b};
    }
};