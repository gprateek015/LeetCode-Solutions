class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        map<int, int> mp;
        for(int i: tasks) {
            mp[i]++;
        }
        for(auto i: mp) {
            if(i.second<2) {
                return -1;
            }
        }
        int ans=0;
        for(auto i: mp) {
            ans += (i.second+2)/3;
        }
        return ans;
    }
};