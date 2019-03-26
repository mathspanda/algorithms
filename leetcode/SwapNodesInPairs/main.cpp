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
    ListNode* swapPairs(ListNode* head) {
    	if (!head || !head->next) {
    		return head;
    	}
    	ListNode *new_head = head->next;
        ListNode *ptr = head;
        ListNode *prev = NULL;
        while (ptr && ptr->next) {
        	ListNode *next = ptr->next;
        	ListNode *nn = next->next;
        	next->next = ptr;
        	ptr->next = nn;
        	if (prev) {
        		prev->next = next;
        	}
        	prev = ptr;
        	ptr = nn;
        }
        return new_head;
    }
};
