class Solution {
private:
public:
    int minCost(string colors, vector<int>& neededTime) {
        int j=0,ans=0;
        while (j<colors.size()) {
            if (colors[j]!=colors[j+1]) {
                j++;
            }
            else {
                int maxi=neededTime[j],sum=neededTime[j];
                while (j<colors.size()&&colors[j]==colors[j+1]) {
                    sum+=neededTime[j+1];
                    maxi=max(maxi,neededTime[j+1]);
                    j++;
                }
                ans+=sum-maxi;
            }
        }
        return ans;
    }
};