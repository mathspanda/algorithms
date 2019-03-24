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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) {
            return NULL;
        }
        if (lists.size() == 1) {
            return lists.front();
        }
        if (lists.size() == 2) {
            return mergeTwoLists(lists[0], lists[1]);
        }
        int mid = lists.size() / 2;
        std::vector<ListNode*> sub1;
        std::vector<ListNode*> sub2;
        for (int i = 0; i < mid; i++) {
            sub1.push_back(lists[i]);
        }
        for (int i = mid; i < lists.size(); i++) {
            sub2.push_back(lists[i]);
        }
        ListNode *l1 = mergeKLists(sub1);
        ListNode *l2 = mergeKLists(sub2);
        return mergeTwoLists(l1, l2);
    }

private:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode temp_head = ListNode(0);
        ListNode *pre = &temp_head;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                pre->next = l1;
                l1 = l1->next;
            } else {
                pre->next = l2;
                l2 = l2->next;
            }
            pre = pre->next;
        }
        if (l1) {
            pre->next = l1;
        }
        if (l2) {
            pre->next = l2;
        }
        return temp_head.next;
    }
};
