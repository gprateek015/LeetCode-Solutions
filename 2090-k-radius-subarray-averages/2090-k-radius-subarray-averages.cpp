class Solution {
public:
    vector<int> getAverages(vector<int>& arr, int k) {
        vector<long long> nums(arr.size(), 0);
        nums[0] = arr[0];
        vector<int> ans(nums.size(), -1);
        for(int i=1; i<nums.size(); i++) {
            nums[i] = nums[i-1] + arr[i];
        }
        for(int i=k; i+k<nums.size(); i++) {
            if(i-k-1 >= 0)
                ans[i] = (nums[i+k] - nums[i-k-1])/(2*k + 1);
            else
                ans[i] = nums[i+k]/(2*k + 1);
        }
        return ans;
    }
};