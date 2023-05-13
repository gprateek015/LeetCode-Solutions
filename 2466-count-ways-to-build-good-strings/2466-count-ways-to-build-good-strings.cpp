class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<long long> answer(200005);
        long long mod  = 1e9+7;
        answer[0] = 1;
        for(int i = 0; i < 100005; i++){
            answer[i + zero] %= mod;
            answer[i + zero] += answer[i];
            answer[i + one] %= mod;
           answer[i + one] += answer[i];
        }
        long long sums = 0;
        for(int i = low; i <= high; i++){
            sums = (sums + answer[i])%mod;
        }
        return sums;
    }
};