class Solution {
    void solve(vector<int>& arr, int k, int x, int i, int j, vector<int> &ans) {
        if(!k) return; 
        if(i<0 && j>arr.size()-1) return;
        // cout << arr[i] << ' ' << arr[j] << endl;
        if(i<0) {
            ans.push_back(arr[j]);
            solve(arr, k-1, x, i, j+1, ans);
            return;
        }
        if(j>arr.size()-1) {
            ans.push_back(arr[i]);
            solve(arr, k-1, x, i-1, j, ans);
            return;
        }
        if(x-arr[i] <= arr[j]-x) {
            ans.push_back(arr[i]);
            solve(arr, k-1, x, i-1, j, ans);
            return;
        }
        ans.push_back(arr[j]);
        solve(arr, k-1, x, i, j+1, ans);
    }
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> ans;
        int i=lower_bound(arr.begin(), arr.end(), x)-arr.begin();
        if(i==arr.size())
            i = arr.size()-1;
        else if(arr[i]!=x && i>0) 
            i--;
        solve(arr, k, x, i, i+1, ans);
        sort(ans.begin(), ans.end());
        return ans;
    }
};