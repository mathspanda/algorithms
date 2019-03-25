/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode new_head = ListNode(0);
        new_head.next = head;
        ListNode *ptr = &new_head;
        while (ptr && ptr->next) {
            if (ptr->next->val == val) {
                ptr->next = ptr->next->next;
            } else {
                ptr = ptr->next;
            }
        }
        return new_head.next;
    }
};
