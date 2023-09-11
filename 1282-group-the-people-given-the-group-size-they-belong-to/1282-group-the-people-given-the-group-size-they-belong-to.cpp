class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        map<int, vector<int>> mp;
        for(int i=0; i<groupSizes.size(); i++) {
            if(mp.find(groupSizes[i]) == mp.end()) {
                mp[groupSizes[i]] = {i};
            } else {
                mp[groupSizes[i]].push_back(i);
            }
        }
        vector<vector<int>> ans;
        for(auto i: mp) {
            int x = i.first;
            vector<int> t;
            while(i.second.size()) {
                t.push_back(i.second.back());
                i.second.pop_back();
                x--;
                if(x==0) {
                    ans.push_back(t);
                    t.clear();
                    x = i.first;
                }
            }
        }
        return ans;
    }
};