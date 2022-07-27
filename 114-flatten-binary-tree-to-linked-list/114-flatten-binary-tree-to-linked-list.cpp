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
    TreeNode* rightMost(TreeNode* root) {
        if(!root->right)
            return root;
        return rightMost(root->right);
    }
public:
    void flatten(TreeNode* root) {
        if(!root)
            return;
        TreeNode *RightMost, *nextRight;
        while(root) {
            if(root->left) {
                RightMost = rightMost(root->left);
                nextRight = root->right;
                root->right = root->left;
                root->left = NULL;
                RightMost->right = nextRight;
            }
            root = root->right;
        }
    }
};