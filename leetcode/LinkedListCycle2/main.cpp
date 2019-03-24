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
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *meet = NULL;
        while (slow && fast) {
            slow = slow->next;
            fast = fast->next;
            if (!fast) {
                return NULL;
            }
            fast = fast->next;
            if (slow == fast) {
                meet = slow;
                break;
            }
        }
        if (meet == NULL) { 
            return NULL;
        }
        while (head && meet) {
            if (head == meet) {
                return head;
            }
            head = head->next;
            meet = meet->next;
        }
        return NULL;
    }
};
