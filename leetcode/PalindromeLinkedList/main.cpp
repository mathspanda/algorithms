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
    bool isPalindrome(ListNode* head) {
    	if (head == NULL) {
    		return true;
    	}
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast->next && fast->next->next) {
        	slow = slow->next;
        	fast = fast->next->next;
        }
        ListNode *half_head = NULL;
        ListNode *half_ptr = slow->next;
        while (half_ptr) {
        	ListNode *next = half_ptr->next;
        	half_ptr->next = half_head;
        	half_head = half_ptr;
        	half_ptr = next;
        }
        slow->next = half_ptr;
        while (head && half_head) {
        	if (head->val != half_head->val) {
        		return false;
        	}
        	head = head->next;
        	half_head = half_head->next;
        }
        return true;
    }
};
