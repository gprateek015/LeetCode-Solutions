class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> ans;
        for(int i=0; i<nums.size(); i++) {
            while(dq.size() && nums[i]>=nums[dq.back()]) {
                dq.pop_back();
            }
            dq.push_back(i);
            if(dq.front()<=i-k)
                dq.pop_front();
            if(i>=k-1) {
                ans.push_back(nums[dq.front()]);
            }
        }
        return ans;
    }
};