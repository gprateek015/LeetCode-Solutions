class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int i=0, j=0;
        int ans = 0;
        map<int, int> mp;
        set<int> st;
        
        while(i<=j && j<fruits.size()) {
            mp[fruits[j]]++;
            st.insert(fruits[j]);
            while(i<=j && st.size()>2) {
                mp[fruits[i]]--;
                if(mp[fruits[i]] == 0) {
                    st.erase(fruits[i]);
                    i++;
                    break;
                }
                i++;
            }
            j++;
            ans = max(ans, j-i);
        }
        return ans;
    }
};