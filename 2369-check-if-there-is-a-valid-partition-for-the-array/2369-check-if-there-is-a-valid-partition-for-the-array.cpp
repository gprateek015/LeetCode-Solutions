class Solution {
    vector<int> dp;
    bool check1(vector<int> &arr, int i) {
        if(arr.size()-i < 2) return 0;
        return arr[i]==arr[i+1];
    }
    bool check2(vector<int> &arr, int i) {
        if(arr.size()-i < 3) return 0;
        return arr[i]==arr[i+1] && arr[i]==arr[i+2];
    }
    bool check3(vector<int> &arr, int i) {
        if(arr.size()-i < 3) return 0;
        return arr[i]+1==arr[i+1] && arr[i]+2==arr[i+2];
    }
public:
    Solution() {
        dp = vector<int>(1e5+5, -1);
    }
    bool validPartition(vector<int> &nums, int i=0) {
        if(i==nums.size()) return true;
        if(dp[i] != -1) return dp[i];
        bool ans = 0;
        if(check1(nums, i)) {
            ans |= validPartition(nums, i+2);
        }
        if(check2(nums, i)) {
            ans |= validPartition(nums, i+3);
        }
        if(check3(nums, i)) {
            ans |= validPartition(nums, i+3);
        }
        return dp[i]=ans;
    }
};