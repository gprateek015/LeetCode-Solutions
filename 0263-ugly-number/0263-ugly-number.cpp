class Solution {
public:
    bool isUgly(int n) {
        if(!n) return 0;
        int factors[] = {2, 3, 5};
        while(n%2 == 0) {
            n/=2;
        }
        while(n%3 == 0) {
            n/=3;
        }
        while(n%5 == 0) {
            n/=5;
        }
        return n==1;
    }
};