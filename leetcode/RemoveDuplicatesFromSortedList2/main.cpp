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
    ListNode* deleteDuplicates(ListNode* head) {
    	if (!head || !head->next) {
    		return head;
    	}
        ListNode new_head = ListNode(0);
        ListNode *ptr = head, *prev = &new_head;
        int val = head->val, count = 0;
        while (ptr->next) {
        	if (ptr->next->val == val) {
        		count++;
        		ptr = ptr->next;
        		continue;
        	}
        	if (count == 0) {
        		prev->next = ptr;
        		prev = ptr;
        	}
        	count = 0;
        	val = ptr->next->val;
        	ptr = ptr->next;
        }
        if (count > 0) {
        	prev->next = NULL;
        } else {
        	prev->next = ptr;
        }
        return new_head.next;
    }
};
