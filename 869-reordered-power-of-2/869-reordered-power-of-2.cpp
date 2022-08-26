class Solution {
    bool check(int a, int b) {
        int n = 0;
        while(a) {
            n++;
            a/=10;
        }
        while(b) {
            n--;
            b/=10;
        }
        return n==0;
    }
public:
    bool reorderedPowerOf2(int n) {
        string s = to_string(n);
        sort(s.begin(), s.end());
        int x = stoi(s);
        if((x&(x-1))==0 and check(n,x)) return 1;
        while(next_permutation(s.begin(), s.end())) {
            x = stoi(s);
            if((x&(x-1))==0 and check(n,x)) return 1;
        }
        return 0;
    }
};