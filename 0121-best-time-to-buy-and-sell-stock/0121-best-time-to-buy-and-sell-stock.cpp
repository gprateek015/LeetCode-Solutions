class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> maxi(prices.size()), mini(prices.size(), 0);
        mini[0] = prices[0];
        for(int i=1; i<prices.size(); i++) {
            mini[i] = min(mini[i-1], prices[i]);
        }
        maxi[prices.size()-1] = prices[prices.size()-1];
        for(int i=prices.size()-2; i>=0; i--) {
            maxi[i] = max(maxi[i+1], prices[i]);
        }
        int ans=0;
        for(int i=0; i<prices.size(); i++) {
            ans = max(ans, maxi[i]-mini[i]);
        }
        return ans;
    }
};