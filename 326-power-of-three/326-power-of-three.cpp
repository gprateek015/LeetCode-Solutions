class Solution {
public:
    bool isPowerOfThree(int n) {
        double a = log10(n)/log10(3);
        return fmod(a, 1)==0;
    }
};