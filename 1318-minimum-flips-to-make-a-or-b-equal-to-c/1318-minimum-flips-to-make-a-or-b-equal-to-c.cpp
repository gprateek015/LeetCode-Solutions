class Solution {
public:
    int minFlips(int a, int b, int c) {
        int x = a | b;
        int ans = 0;
        int mask = 0;
        for(int i=0; i<32; i++) {
            mask = 1<<i;
            if((x & mask) != (c & mask)) {
                if((c&mask) != 0) {
                    ans++;
                } else {
                    if(a&mask) 
                        ans++;
                    if(b&mask)
                        ans++;
                }
            }
        }
        return ans;
    }
};
