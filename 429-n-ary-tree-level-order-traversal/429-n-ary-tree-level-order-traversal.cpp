/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if(!root) return {};
        queue<Node*> q;
        q.push(root);
        int curr = 1, next = 0;
        vector<vector<int>> ans;
        vector<int> t;
        while(q.size()) {
            Node* cur = q.front();
            q.pop();
            t.push_back(cur->val);
            curr--;
            for(auto &x: cur->children) {
                q.push(x);
                next++;
            }
            if(!curr) {
                curr = next;
                next = 0;
                ans.push_back(t);
                t.clear();
            }
        }
        return ans;
    }
};