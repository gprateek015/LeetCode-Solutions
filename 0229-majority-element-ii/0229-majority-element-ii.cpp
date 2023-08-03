class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int ele1=INT_MIN, ele2=INT_MIN;
        int c1=0, c2=0;
        for(int i: nums) {
            if(c1==0 && ele2!=i) {
                ele1 = i;
                c1 = 1;
            } else if(c2==0 && ele1!=i) {
                ele2 = i;
                c2 = 1;
            } else if(ele1==i) {
                c1++;
            } else if(ele2==i) {
                c2++;
            } else {
                c1--;
                c2--;
            }
        }
        vector<int> ans;
        c1=0; c2=0;
        for(int i: nums) {
            if(i==ele1) c1++;
            if(i==ele2) c2++;
        }
        if(c1 > nums.size()/3) ans.push_back(ele1);
        if(c2 > nums.size()/3) ans.push_back(ele2);
        return ans;
    }
};