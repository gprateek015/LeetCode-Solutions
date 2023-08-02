class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int c=0;
        int ele;
        for(int i=0; i<nums.size(); i++) {
            if(c==0) ele = nums[i];
            c += nums[i]==ele ? +1 : -1;
        }
        return ele;
    }
};