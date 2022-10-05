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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        // 1. BFS - figure out nodes at level depth-1 and modify them
        // base case - depth == 1; make a new root
        if(depth == 1){
            TreeNode *prevRoot = root;
            root = new TreeNode(val);
            root->left = prevRoot;
            return root;
        }
        // do BFS
        queue<TreeNode*> q;
        q.push(root);
        int lvl = 1;
        while(!q.empty()){
            int lvl_size = q.size();
            while(lvl_size--){
                TreeNode* curr = q.front();
                q.pop();
                if(lvl == depth-1){
                    cout << curr->val;
                        
                    // left 
                    TreeNode *tLeft = new TreeNode(val);           
                    if(curr->left) { 
                        tLeft->left = curr->left;
                    }
                    curr->left = tLeft;
                    
                    // right
                    TreeNode *tRight = new TreeNode(val);
                    if(curr->right){
                        tRight->right = curr->right;
                    }
                    curr->right = tRight;
                    
                }
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
            lvl++;
        }
        return root;
    }
};