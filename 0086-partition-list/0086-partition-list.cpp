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
    ListNode* partition(ListNode* head, int x) {
        if(!head) return head;
        ListNode* curr1 = nullptr, *curr2 = nullptr;
        ListNode* head1 = nullptr, *head2 = nullptr;
        if(head->val < x) {
            curr1 = head;
            head1 = head;
        } else {
            curr2 = head;
            head2 = head;
        }
        head = head->next;
        while(head) {
            if(head->val < x) {
                if(head1) {
                    curr1->next = head;
                    curr1 = curr1->next;
                } else {
                    curr1 = head;
                    head1 = head;
                }
            } else {
                if(head2) {
                    curr2->next = head;
                    curr2 = curr2->next;
                } else {
                    curr2 = head;
                    head2 = head;
                }
            }
            head = head->next;
        }
        if(curr2)
            curr2->next = nullptr;
        if(!head1) {
            return head2;
        }
        curr1->next = head2;
        return head1;
    }
};