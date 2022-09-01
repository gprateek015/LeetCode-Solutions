/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    multiset<int> st;
    void dfs(TreeNode *root, int& ans) {
        if(!root) return;
        st.insert(root->val);
        // cout << *(--st.end()) << endl;
        int last_val = *(--st.end());
        if(last_val == root->val) {
            ans++;
        }
        dfs(root->left, ans);
        dfs(root->right, ans);
        st.erase(st.find(root->val));
        return;
    }
public:
    int goodNodes(TreeNode* root) {
        int ans = 0;
        dfs(root, ans);
        return ans;
    }
};