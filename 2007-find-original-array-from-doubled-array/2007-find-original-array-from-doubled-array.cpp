class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        if(changed.size()%2!=0) return {};
        sort(changed.begin(), changed.end());
        vector<int> origional;
        map<int, int> mp;
        for(int i: changed) {
            mp[i]++;
        }
        for(int i=0; i<changed.size(); i++) {
            if(!mp[changed[i]]) continue;
            mp[changed[i]]--;
            if(binary_search(changed.begin(), changed.end(), 2*changed[i])) {
                if(mp[2*changed[i]] > 0) {
                    origional.push_back(changed[i]);
                    mp[2*changed[i]]--;
                }
            }
        }
        vector<int> empty;
        return ((origional.size() == changed.size()/2) ? origional : empty);
    }
};