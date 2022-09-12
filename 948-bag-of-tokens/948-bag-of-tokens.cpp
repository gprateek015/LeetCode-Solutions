class Solution {
public:
    int bagOfTokensScore(vector<int>& t, int power) {
        vector<int> v(t);
        sort(t.begin(), t.end());
        sort(v.rbegin(), v.rend());
        int ans=0, cur=0;
        int i=0, j=0;
        while(i<t.size() || j<v.size()) {
            if(power >= t[i]) {
                cur++;
                power -= t[i++];
                v.pop_back();
            } else {
                if(cur<1) break;
                cur--;
                power += v[j++];
                t.pop_back();
            }
            ans = max(ans, cur);
        }
        return ans;
    }
};