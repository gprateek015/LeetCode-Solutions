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
    vector<int> arr;
    void helper(TreeNode* root) {
        if(!root) return;
        helper(root->left);
        arr.push_back(root->val);
        helper(root->right);
    }
public:
    int minDiffInBST(TreeNode* root) {
        int ans = 1e9;
        helper(root);
        for(int i=0; i<arr.size()-1; i++) {
            ans = min(ans, arr[i+1]-arr[i]);
        }
        return ans;
    }
};