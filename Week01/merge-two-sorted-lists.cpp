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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (!l1 && !l2) return nullptr;
        if (!l1) return l2;
        if (!l2) return l1;
        if (l1->val > l2->val) swap(l1, l2);
        ListNode* head = l1;
        while (l2) {
            if (!head->next) {
                head->next = l2;
                break;
            }
            else {
                if (head->next->val < l2->val) {
                    head = head->next;
                }
                else {
                    ListNode* t = l2->next;
                    //while (t && t->val < head->next->val) t = t->next;
                    l2->next = head->next;
                    head->next = l2;
                    head = head->next;
                    l2 = t;
                }
            }
        }
        return l1;
    }
};
