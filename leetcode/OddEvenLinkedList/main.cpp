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
    ListNode* oddEvenList(ListNode* head) {
    	if (!head || !head->next) {
    		return head;
    	}
        ListNode *odd_head = head;
        ListNode *even_head = head->next;
        ListNode *odd_ptr = odd_head, *even_ptr = even_head;
        while (odd_ptr->next && even_ptr->next) {
        	odd_ptr->next = odd_ptr->next->next;
        	odd_ptr = odd_ptr->next;
        	even_ptr->next = even_ptr->next->next;
        	even_ptr = even_ptr->next;
        }
        odd_ptr->next = even_head;
        return odd_head;
    }
};
