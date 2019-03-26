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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    	ListNode head = ListNode(0);
    	ListNode *cur = &head;
        int carry = 0;
        while (l1 || l2) {
        	int val_l1 = !l1 ? 0 : l1->val;
        	int val_l2 = !l2 ? 0 : l2->val;
        	int temp = val_l1 + val_l2 + carry;
        	carry = temp / 10;
        	temp = temp % 10;
        	ListNode *new_node = new ListNode(temp);
        	cur->next = new_node;
        	cur = new_node;
        	if (l1) l1 = l1->next;
        	if (l2) l2 = l2->next;
        }
        if (carry) {
        	cur->next = new ListNode(1);
        }
        return head.next;
    }
};
