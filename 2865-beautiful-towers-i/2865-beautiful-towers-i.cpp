class Solution {
public:
    long long maximumSumOfHeights(vector<int>& maxHeights) {
        long long int ans = 0;
        for(int i=0; i<maxHeights.size(); i++) {
            long long int curr = 0;
            int right = maxHeights[i];
            for(int j=i-1; j>=0; j--) {
                right = min(maxHeights[j], right);
                curr += right;
            }
            int left = maxHeights[i];
            for(int j=i+1; j<maxHeights.size(); j++) {
                left = min(maxHeights[j], left);
                curr += left;
            }
            curr += maxHeights[i];
            ans = max(curr, ans);
        }
        return ans;
    }
};