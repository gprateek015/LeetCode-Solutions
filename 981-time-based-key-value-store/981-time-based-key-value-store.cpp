class TimeMap {
    unordered_map<string, set<int>> mp;
    unordered_map<string, string> ans;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].insert(timestamp);
        ans[key+to_string(timestamp)] = value;
    }
    
    string get(string key, int timestamp) {
        auto it = mp[key].upper_bound(timestamp);
        if(it==mp[key].begin()) {
            return "";
        }
        --it;
        return ans[key+to_string(*it)];
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */