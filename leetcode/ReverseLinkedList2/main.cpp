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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        int change_len = n - m + 1;
        ListNode *result = head;
        ListNode *pre_head = NULL;
        while (head && --m) {
            pre_head = head;
            head = head->next;
        }
        ListNode *seg_tail = head;
        ListNode *new_head = NULL;
        while (head && change_len--) {
            ListNode *next = head->next;
            head->next = new_head;
            new_head = head;
            head = next;
        }
        seg_tail->next = head;
        if (pre_head) {
            pre_head->next = new_head;
        } else {
            result = new_head;
        }
        return result;
    }
};
