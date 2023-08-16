class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        int st = 0, end = nums.size()-1;
        while(st<=end) {
            if(st==end) return nums[st];
            int mid = (st+end)/2;
            if(nums[mid] == nums[mid-1]) {
                if((mid-2 - st + 1) % 2 == 0) {
                    st = mid+1;
                } else {
                    end = mid-2;
                }
            } else if(nums[mid] == nums[mid+1]) {
                if((end - mid+2 + 1) % 2 == 0) {
                    end = mid-1;
                } else {
                    st = mid+2;
                }
            } else {
                return nums[mid];
            }
        }
        return -1;
    }
};