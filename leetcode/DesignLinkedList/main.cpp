class MyLinkedList {
public:
    /** Initialize your data structure here. */
    MyLinkedList() {
        head = new ListNode(0);
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        ListNode *ptr = head;
        int i = 0;
        while (ptr->next) {
            ptr = ptr->next;
            if (i == index) {
                return ptr->val;
            }
            i++;
        }
        return -1;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        ListNode *new_node = new ListNode(val);
        new_node->next = head->next;
        head->next = new_node;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        ListNode *ptr = head;
        while (ptr->next) {
            ptr = ptr->next;
        }
        ptr->next = new ListNode(val);
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        ListNode *ptr = head, *prev = head;
        int i = 0;
        while (ptr) {
            prev = ptr;
            ptr = ptr->next;
            if (i == index) {
                prev->next = new ListNode(val);
                prev->next->next = ptr;
                return;
            }
            i++;
        }
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        ListNode *ptr = head, *prev = head;
        int i = 0;
        while (ptr) {
            prev = ptr;
            ptr = ptr->next;
            if (i == index) {
                if (ptr) {
                    prev->next = ptr->next;
                } else {
                    prev->next = NULL;
                }
                return;
            }
            i++;
        }
    }

private:
    struct ListNode {
        int val;
        ListNode *next;
        ListNode(int x): val(x), next(NULL) {}
    };
    ListNode *head;
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList obj = new MyLinkedList();
 * int param_1 = obj.get(index);
 * obj.addAtHead(val);
 * obj.addAtTail(val);
 * obj.addAtIndex(index,val);
 * obj.deleteAtIndex(index);
 */
