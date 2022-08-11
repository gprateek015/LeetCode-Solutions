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
public:
    bool isValidBST(TreeNode* root, long l=LONG_MIN, long r=LONG_MAX) {
        if(!root) return true;
        if(root->val <= l || root->val >= r) 
            return false;
        bool ans = isValidBST(root->left, l, min(r, (long)root->val)) && isValidBST(root->right, max(l, (long)root->val), r);
        if(root->left) {
            ans = ans && (root->val > root->left->val);
        }
        if(root->right) {
            ans = ans && (root->val < root->right->val);
        }
        return ans;
    }
};