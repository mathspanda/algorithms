/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

int get_list_len(ListNode *head) {
    int len = 0;
    while (head) {
        len++;
        head = head->next;
    }
    return len;
}

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA = get_list_len(headA);
        int lenB = get_list_len(headB);
        if (lenA > lenB) {
            for (int i = 1; i <= lenA - lenB; i++) {
                headA = headA->next;
            }
        } else {
            for (int i = 1; i <= lenB - lenA; i++) {
                headB = headB->next;
            }
        }
        
        while (headA && headB) {
            if (headA == headB) {
                return headA;
            }
            headA = headA->next;
            headB = headB->next;
        }
        return NULL;
    }
};
