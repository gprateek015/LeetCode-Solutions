class Solution {
public:
    double myPow(double x, int n) {
        if(n==0) return 1;
        if(n==1) return x;
        bool flag = n < 0;
        n = abs(n);
        double half = myPow(x, n/2);
        if(n%2 != 0) {
            if(flag) {
                return 1/(half*half*x);
            }
            return half*half*x;
        }
        if(flag) {
                return 1/(half*half);
            }
        return half*half;
    }
};