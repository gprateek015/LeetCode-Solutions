class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int> ans;
        for(int i=0; i<digits.size(); i++) {
            int a = digits[i];
            if(a == 0) continue;
            for(int j=0; j<digits.size(); j++) {
                if(i==j) continue;
                for(int k=0; k<digits.size(); k++) {
                    if(i==k || j==k) continue;
                    if(digits[k]%2!=0) continue;
                    ans.push_back(100*a + 10*digits[j] + digits[k]);
                }
            }
        }
        sort(ans.begin(), ans.end());
        ans.erase(unique(ans.begin(), ans.end()), ans.end());
        return ans;
    }
};