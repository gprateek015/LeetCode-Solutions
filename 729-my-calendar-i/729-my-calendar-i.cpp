class MyCalendar {
    vector<pair<int, int>> vii;
public:
    MyCalendar() {
        vii = vector<pair<int, int>>();
    }
    
    bool book(int start, int end) {
        for(auto &it: vii) {
            int s = it.first, e = it.second;
            if(start >= s && start < e) return false;
            if(start < s && end > s) return false;
        }
        vii.push_back({start, end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */