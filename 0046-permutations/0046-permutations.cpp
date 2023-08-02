class Solution {
    
    void helper(vector<int>& nums, vector<int> &curr, vector<vector<int>> &ans) {
        bool flag = 0;
        for(int i=0; i<nums.size(); i++) {
            if(find(curr.begin(), curr.end(), nums[i]) == curr.end()) {
                flag = 1;
                curr.push_back(nums[i]);
                helper(nums, curr, ans);
                curr.pop_back();
            }
        }
        if(!flag)
            ans.push_back(curr);
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;
        helper(nums, curr, ans);
        return ans;
    }
};