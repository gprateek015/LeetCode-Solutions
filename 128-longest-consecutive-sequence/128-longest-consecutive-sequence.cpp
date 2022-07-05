class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(auto &i: nums) {
            mp[i] = 0;
        }
        for(int &i: nums) {
            if(mp[i]!=0) continue;
            mp[i]=1;
            int a = i+1;
            while(mp.find(a)!=mp.end()) {
                if(mp[a]!=0) {
                    a+=mp[a];
                    break;
                }
                mp[a]=1;
                a++;
            }
            mp[i] = a-i;
        }
        int ans=0;
        for(auto &i: mp) {
            ans = max(ans, i.second);
        }
        return ans;
    }
};