/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> a(m, vector<int> (n, -1));
        int l=0;
        ListNode* curr = head;
        while(l<=m/2) {
            for(int i=l; i<n-l; i++) {
                a[l][i] = curr->val;
                curr = curr->next;
                if(!curr) {
                    return a;
                }
            }
            for(int i=l+1; i<m-l; i++) {
                a[i][n-l-1] = curr->val;
                curr = curr->next;
                if(!curr) {
                    return a;
                }
            }
            for(int i=n-2-l; i>=l; i--) {
                a[m-1-l][i] = curr->val;
                curr = curr->next;
                if(!curr) {
                    return a;
                }
            }
            for(int i=m-2-l; i>l; i--) {
                a[i][l] = curr->val;
                curr = curr->next;
                if(!curr) {
                    return a;
                }
            }
            l++;
        }
        return a;
    }
};