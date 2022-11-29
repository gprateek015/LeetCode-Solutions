class RandomizedSet {
    unordered_map<int, int> mp;
    vector<int> arr;
public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(mp.find(val)==mp.end()) {
            mp[val] = arr.size();
            arr.push_back(val);
            return true;
        }
        return false;
    }
    
    bool remove(int val) {
        if(mp.find(val)==mp.end()) {
            return false;
        }
        arr[mp[val]] = arr.back();
        mp[arr.back()] = mp[val];
        arr.pop_back();
        mp.erase(val);
        return true;
    }
    
    int getRandom() {
        int rand_ind = rand() % arr.size();
        return arr[rand_ind];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */