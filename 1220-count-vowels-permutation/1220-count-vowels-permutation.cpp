const int mod = 1e9+7;
class Solution {
    vector<vector<int>> dp; 
    int solve(char c, int n) {
        if(n==1) return 1;
        if(n<=0) return 0;
        if(dp[n][c-'a']!=-1)
            return dp[n][c-'a'];
        long long ans = 0;
        if(c=='a') {
            ans = (ans + solve('e', n-1))%mod;
        } else if(c=='e') {
            ans = (ans + solve('a', n-1))%mod;
            ans = (ans + solve('i', n-1))%mod;
        } else if(c=='i') {
            ans = (ans + solve('a', n-1))%mod;
            ans = (ans + solve('e', n-1))%mod;
            ans = (ans + solve('o', n-1))%mod;
            ans = (ans + solve('u', n-1))%mod;
        } else if(c=='o') {
            ans = (ans + solve('i', n-1))%mod;
            ans = (ans + solve('u', n-1))%mod;
        } else {
            ans = (ans + solve('a', n-1))%mod;
        }
        return dp[n][c-'a'] = ans%mod;
    }
public:
    int countVowelPermutation(int n) {
        long long ans = 0;
        vector<char> vowels;
        dp = vector<vector<int>>(n+1, vector<int>(27, -1));
        vowels = {'a', 'e', 'i', 'o', 'u'};
        for(char c: vowels) {
            ans = (ans + solve(c, n))%mod;
        }
        return ans%mod;
    }
};