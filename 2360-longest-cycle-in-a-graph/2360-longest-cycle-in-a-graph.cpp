class Solution {
    int ans = -1;
    void dfs(int i, vector<int>& edges, vector<bool> &vis, int lvl, vector<int> &lvls) {
        if(i==-1) return;
        if(lvls[i]!=-1) {
            ans = max(ans, lvl - lvls[i]);
            return;
        }
        if(!vis[i]) {
            lvls[i] = lvl;
            vis[i]=1;
            dfs(edges[i], edges, vis, lvl+1, lvls);   
        }
        lvls[i] = -1;
    }
public:
    int longestCycle(vector<int>& edges) {
        vector<bool> vis(edges.size(), 0);
        vector<int> lvls(edges.size(), -1);
        for(int i=0; i<edges.size(); i++) {
            if(!vis[i]) {
                dfs(i, edges, vis, 0, lvls);
            }
        }
        
        return ans;
    }
};