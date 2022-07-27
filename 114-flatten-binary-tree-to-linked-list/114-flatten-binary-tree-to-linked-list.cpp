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
void helper(TreeNode* root, vector<int> &ans) {
    ans.push_back(root->val);
    if(root->left != nullptr)
        helper(root->left, ans);
    if(root->right != nullptr)
        helper(root->right, ans);
}
class Solution {
public:
    void flatten(TreeNode* root) {
        if(root == nullptr)
            return;
        vector<int> ans;
        helper(root, ans);
        for(int i=0; i<ans.size(); i++) {
            root->val = ans[i];
            if(i != ans.size()-1) {
            root->left = nullptr;
            root->right = new TreeNode();
            root = root->right;
            }
        }
    }
};