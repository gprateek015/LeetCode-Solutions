class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for(int &i: nums) {
            if(nums[abs(i)] < 0) 
                return abs(i);
            nums[abs(i)] = -1 * nums[abs(i)];
        }
        return 0;
    }
};