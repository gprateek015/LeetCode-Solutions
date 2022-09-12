class Solution {
public:
    int bagOfTokensScore(vector<int>& t, int power) {
        sort(t.begin(), t.end());
        int ans=0, cur=0;
        int i=0, j=t.size()-1;
        while(i<=j) {
            if(power >= t[i]) {
                cur++;
                power -= t[i++];
            } else {
                if(cur<1) break;
                cur--;
                power += t[j--];
            }
            ans = max(ans, cur);
        }
        return ans;
    }
};