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
        ListNode new_node = ListNode(0);
        new_node.next = head;
        int val = head->val;
        while (head->next) {
        	if (head->next->val == val) {
        		head->next = head->next->next;
        		continue;
        	}
        	val = head->next->val;
        	head = head->next;
        }
        return new_node.next;
    }
};
