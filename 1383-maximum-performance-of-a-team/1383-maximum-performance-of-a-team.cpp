#define ll long long
const int mod = 1e9+7;
class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pair<int, int>> v;
        for(int i=0; i<n; i++) {
            v.push_back({efficiency[i], speed[i]});
        }
        sort(v.rbegin(), v.rend());
        priority_queue<int, vector<int>, greater<int>> pq;
        ll totalSpeed=0, ans=0;
        for(int i=0; i<n; i++) {
            if(pq.size() == k) {
                totalSpeed -= pq.top();
                pq.pop();
            }
            totalSpeed += v[i].second;
            pq.push(v[i].second);
            ans = max(ans, totalSpeed*v[i].first);
        }
        return ans%mod;
    }
};