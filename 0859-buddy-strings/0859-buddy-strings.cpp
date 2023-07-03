class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if(s.size() != goal.size()) return 0;
        vector<int> arr;
        bool repeat = 0;
        vector<int> freq(26, 0);
        for(int i=0; i<s.size(); i++) {
            if(s[i] != goal[i]) arr.push_back(i);
            else {
                freq[s[i]-'a']++;
                if(freq[s[i]-'a'] > 1) repeat=1;
            }
        }
        if(arr.size()==2 && s[arr[0]]==goal[arr[1]] && s[arr[1]]==goal[arr[0]]) return 1;
        if(arr.size()==0 && repeat) return 1;
        return 0;
    }
};