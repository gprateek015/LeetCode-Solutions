class Solution {
public:
    int romanToInt(string s) {
        int ans = 0;
        map<char, int> mp;
        mp['I'] = 1;
        mp['V'] = 5;
        mp['X'] = 10;
        mp['L'] = 50;
        mp['C'] = 100;
        mp['D'] = 500;
        mp['M'] = 1000;
        for(int i=0; i<s.size(); i++) {
            int c = mp[s[i]], d=-1;
            if(i<s.size()-1) {
                d = mp[s[i+1]];
            }
            if(d > c) {
                ans += d-c;
                i++;
            } else {
                ans += c;
            }
        }
        return ans;
    }
};