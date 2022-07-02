class Solution {
public:
    int maxArea(int h, int w, vector<int>& hc, vector<int>& vc) {
        sort(hc.begin(), hc.end());
        sort(vc.begin(), vc.end());
        long long a=hc[0]-0, b=vc[0]-0;
        for(int i=1; i<hc.size(); i++) 
            a = max(int(a), hc[i]-hc[i-1]);
        for(int i=1; i<vc.size(); i++) 
            b = max(int(b), vc[i]-vc[i-1]);
        a = max(int(a), h-hc[hc.size()-1]);
        b = max(int(b), w-vc[vc.size()-1]);
        int m = 1e9+7;
        return (a*b)%m;
    }
};