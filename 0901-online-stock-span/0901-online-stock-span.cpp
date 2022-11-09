class StockSpanner {
    stack<pair<int, int>> st;
public:    
    int next(int price) {
        int curr = 1;
        while(st.size() && st.top().first<=price) {
            curr += st.top().second;
            st.pop();
        }
        st.push({price, curr});
        return curr;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */