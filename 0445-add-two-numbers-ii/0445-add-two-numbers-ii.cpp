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
    ListNode* reverse(ListNode* l) {
        ListNode* curr = l;
        ListNode* prev = NULL;
        ListNode* next = NULL;
        while(curr && curr->next) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        curr->next = prev;
        return curr;
    }
    // ListNode* add(ListNode* l1, ListNode* l2, int carry) {
    //     if(!l1 && !l2) return NULL;
    //     if(!l1) {
    //         ListNode* temp = new ListNode((l2->val+carry)%10);
    //         temp->next = add(l1, l2->next, carry);
    //         return
    //     }
    // }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = reverse(l1);
        l2 = reverse(l2);
        ListNode* ans = new ListNode(0);
        ListNode* res = ans;
        int carry = 0;
        while(l1 && l2) {
            ans->next = new ListNode((l1->val+l2->val+carry)%10);
            carry = (l1->val+l2->val+carry)/10;
            l1 = l1->next;
            l2 = l2->next;
            ans = ans->next;
        }
        while(l1) {
            ans->next = new ListNode((l1->val+carry)%10);
            ans = ans->next;
            carry = (l1->val+carry)/10;
            l1 = l1->next;
        }
        while(l2) {
            ans->next = new ListNode((l2->val+carry)%10);
            ans = ans->next;
            carry = (l2->val+carry)/10;
            l2 = l2->next;
        }
        if(carry) {
            ans->next = new ListNode(carry);
        }
        return reverse(res->next);
    }
};