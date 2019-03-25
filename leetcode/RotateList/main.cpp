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
    ListNode* rotateRight(ListNode* head, int k) {
    	if (!head || !head->next || !k) {
    		return head;
    	}
    	ListNode *ptr = head;
        int length = 1;
        while (ptr->next) {
        	length++;
        	ptr = ptr->next;
        }
        if (k % length == 0) {
        	return head;
        }
        int step = length - k % length;
        ListNode *last = ptr;
        ptr = head;
        while (--step) {
        	ptr = ptr->next;
        }
        last->next = head;
        head = ptr->next;
        ptr->next = NULL;
        return head;
    }
};
