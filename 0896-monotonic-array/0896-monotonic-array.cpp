class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        if(nums.size()==1) return true;
        int neg=0, pos=0;
        for(int i=1; i<nums.size(); i++) {
            if(nums[i]-nums[i-1] > 0) pos++;
            else if(nums[i]-nums[i-1] < 0) neg++;
        }
        return neg==0 || pos==0;
    }
};