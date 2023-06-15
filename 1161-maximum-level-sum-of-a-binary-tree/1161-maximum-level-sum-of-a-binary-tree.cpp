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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int x = 0, sum = INT_MIN, lvl=0;
        while(q.size()) {
            int s = q.size();
            cout << s << endl;
            int lvl_sum = 0;
            lvl++;
            while(s--) {
                TreeNode* curr = q.front();
                lvl_sum += curr->val;
                q.pop();
                if(curr->left) 
                    q.push(curr->left);
                if(curr->right) 
                    q.push(curr->right);
            }
            if(lvl_sum > sum) {
                sum = lvl_sum;
                x = lvl;
            }
        }
        return x;
    }
};