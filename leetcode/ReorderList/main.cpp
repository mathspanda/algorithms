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
    void reorderList(ListNode* head) {
    	if (!head || !head->next) {
    		return;
    	}
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast->next && fast->next->next) {
        	fast = fast->next->next;
        	slow = slow->next;
        }
        ListNode *half_head = NULL;
        ListNode *half_ptr = slow->next;
        slow->next = NULL;
        while (half_ptr) {
        	ListNode *next = half_ptr->next;
        	half_ptr->next = half_head;
        	half_head = half_ptr;
        	half_ptr = next;
        }

        ListNode *ptr = head;
        half_ptr = half_head;
        while (ptr && half_ptr) {
        	ListNode *next = ptr->next;
        	ListNode *half_next = half_ptr->next;
        	ptr->next = half_ptr;
        	half_ptr->next = next;
        	ptr = next;
        	half_ptr = half_next;
        }
    }
};
