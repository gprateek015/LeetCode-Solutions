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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int> > res;
        if(root==nullptr) return res;
        vector<int> a;
        q.push(root);
        while(!q.empty()) {
            int s = q.size();
            for(int i=0; i<s; i++) {
                TreeNode* temp = q.front();
            
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            
                a.push_back(temp->val);
                        
                q.pop();
            }
            res.push_back(a);
            a.clear();
        }

        return res;
    }
};