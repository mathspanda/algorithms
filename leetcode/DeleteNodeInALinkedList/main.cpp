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
    void deleteNode(ListNode* node) {
        ListNode *new_node = node;
        ListNode *prev = NULL;
        while (new_node->next) {
        	new_node->val = new_node->next->val;
        	prev = new_node;
        	new_node = new_node->next;
        }
        prev->next = NULL;
    }
};
