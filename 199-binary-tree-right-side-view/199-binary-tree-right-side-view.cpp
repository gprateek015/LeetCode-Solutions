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
    vector<int> rightSideView(TreeNode* root) {
        if(!root) {
            return {};
        }
        queue<TreeNode*> q;
        vector<vector<int>> a;
        q.push(root);
        int x = 1, next=0;
        vector<int> t;
        while(q.size()) {
            TreeNode* curr = q.front();
            q.pop();
            x--;
            if(curr->left) {
                q.push(curr->left);
                next++;
            }
            if(curr->right) {
                q.push(curr->right);
                next++;
            }
            t.push_back(curr->val);
            if(!x) {
                a.push_back(t);
                x = next;
                next=0;
                t.clear();
            }
        }
        for(auto &it: a) {
            t.push_back(it.back());
        }
        return t;
    }
};