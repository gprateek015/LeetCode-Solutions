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
    int solve(TreeNode* root) {
        if(!root)
            return 0;
        int left = solve(root->left);
        int right = solve(root->right);
        if(!left) 
            root->left = NULL;
        if(!right)
            root->right = NULL;
        return left + right + root->val;
    }
public:
    TreeNode* pruneTree(TreeNode* root) {
        if(!solve(root)) {
            return NULL;
        }
        return root;
    }
};