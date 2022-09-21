class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int sum = 0;
        for(int i: nums) {
            if(i%2==0)
                sum += i;
        }
        vector<int> ans;
        for(auto q: queries) {
            int x = nums[q[1]];
            if(x%2==0) 
                sum -= x;
            nums[q[1]] += q[0];
            if(nums[q[1]]%2==0) 
                sum += nums[q[1]];
            ans.push_back(sum);
        }
        return ans;
    }
};