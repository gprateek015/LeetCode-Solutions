class Solution {
public:
    int integerBreak(int n) {
        if(n==2) return 1;
        if(n==3) return 2;
        int x = n/3;
        int a = (n%3);
        if(a==0)
            return pow(3, x);
        if(a==1)
            return pow(3, x-1)*4;
        return pow(3, x)*2;
    }
};