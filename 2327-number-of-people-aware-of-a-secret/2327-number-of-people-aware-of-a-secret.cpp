class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<long long> ans(n, 0);
        ans[0]=1;
        int d=0, f=0, i=1;
        long long sum = 0;
        int m = 1e9+7;
        for(; i<n; i++) {
            if(i-d == delay) {
                sum = (sum+ans[d])%m;
                d++;
            }
            if(i-f == forget) {
                sum = (sum-ans[f])%m;
                f++;
            }
            ans[i]=sum%m;
        }
        // for(int i=0; i<n; i++) 
        //     cout << ans[i] << ' ';
        long long a=0;
        while(f<n) {
            a = (a+ans[f])%m;
            f++;
        }
        return a<0 ? a+m : a;
    }
};