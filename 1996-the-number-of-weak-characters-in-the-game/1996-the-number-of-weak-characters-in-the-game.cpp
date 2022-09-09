class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& prop) {
        sort(prop.begin(), prop.end());
        vector<int> arr(prop.size(), 0);
        int maxi = prop[prop.size()-1][1];
        int oldMaxi = 0;
        int maxi2 = prop[prop.size()-1][0];
        for(int i=prop.size()-1; i>=0; i--) {
            maxi = max(maxi, prop[i][1]);
            int j = i;
            while(j>=0 && prop[i][0] == prop[j][0]) {
                arr[j] = oldMaxi;
                j--;
            }
            i = j+1;
            oldMaxi = maxi;
        }
        int ans = 0;
        for(int i=0; i<prop.size(); i++) {
            if(prop[i][1] < arr[i]) {
                ans++;
            }
        }
        return ans;
    }
};