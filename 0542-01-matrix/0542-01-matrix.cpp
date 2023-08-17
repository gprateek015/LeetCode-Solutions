class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        queue<pair<int, int>> q;
        vector<vector<int>> ans(mat.size(), vector<int>(mat[0].size()));
        vector<vector<bool>> vis(mat.size(), vector<bool>(mat[0].size(), 0));
        for(int i=0; i<mat.size(); i++) {
            for(int j=0; j<mat[0].size(); j++) {
                if(mat[i][j] == 0) {
                    q.push({i,j});
                    vis[i][j] = 1;
                }
            }
        }
        int d = 0;
        int x[] = {0,0,1,-1};
        int y[] = {1,-1,0,0};
        while(q.size()) {
            int n = q.size();
            while(n--) {
                int i=q.front().first, j=q.front().second;
                q.pop();
                ans[i][j] = d;
                for(int a=0; a<4; a++) {
                    if(i+x[a]>=0 && i+x[a]<mat.size() && j+y[a]>=0 && j+y[a]<mat[0].size() && !vis[i+x[a]][j+y[a]]) {
                        q.push({i+x[a], j+y[a]});
                        vis[i+x[a]][j+y[a]] = 1;
                    }
                }
            }
            d++;
        }
        return ans;
    }
};