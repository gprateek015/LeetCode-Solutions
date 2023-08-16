class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        int k = (n+m)/2;
        int i=0, j=0, prev=-1, ans=-1;
        while(i<n || j<m) {
            prev = ans;
            if(i<n && j<m) {
                if(nums1[i] < nums2[j]) {
                    ans = nums1[i++];
                } else {
                    ans = nums2[j++];
                }
            } else {
                if(i<n) {
                    ans = nums1[i++];
                } else {
                    ans = nums2[j++];
                }
            }
            if(i+j == k+1) break;
        }
        if((n+m)%2==0) {
            return (double)(ans+prev)/2;
        } 
        return ans;
    }
};