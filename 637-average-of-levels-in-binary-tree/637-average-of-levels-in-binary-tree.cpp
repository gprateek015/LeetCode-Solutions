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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        queue<TreeNode*> q;
        q.push(root);
        int next = 0, cur = 1;
        long long sum = 0, t = 1;
        while(q.size()) {
            TreeNode* curr = q.front();
            q.pop();
            sum += curr->val;
            if(curr->left) {
                q.push(curr->left);
                next++;
            }
            if(curr->right) {
                q.push(curr->right);
                next++;
            }
            if((--cur) == 0) {
                ans.push_back((double)sum / t);
                cur = next;
                t = next;
                next = 0;
                sum = 0;
            }
        }
        return ans;
    }
};