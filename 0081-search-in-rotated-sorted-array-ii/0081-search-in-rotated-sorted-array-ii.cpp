class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int st=0, end=nums.size()-1;
        while(st<=end) {
            int mid = (st+end)/2;
            if(nums[mid] == target) return 1;
            if((nums[st] == nums[mid]) && (nums[end] == nums[mid])) {
                st++;
                end--;
            } else if(nums[st] <= nums[mid]) {
                if(target>=nums[st] && target<=nums[mid]) {
                    end = mid-1;
                } else {
                    st = mid+1;
                }
            } else if(nums[mid] <= nums[end]) {
                if(target>=nums[mid] && target<=nums[end]) {
                    st = mid+1;
                } else {
                    end = mid-1;
                }
            }
        }
        return 0;
    }
};