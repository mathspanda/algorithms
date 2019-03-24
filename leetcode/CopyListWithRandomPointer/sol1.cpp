/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};
*/
// Hash.
class Solution {
public:
    Node* copyRandomList(Node* head) {
        std::map<Node *, Node *> node_map;
        Node new_head(0, NULL, NULL);
        Node *new_ptr = &new_head;
        Node *ptr = head;
        while (ptr) {
            new_ptr->next = new Node(ptr->val, NULL, NULL);
            node_map[ptr] = new_ptr->next;
            new_ptr = new_ptr->next;
            ptr = ptr->next;
        }
        ptr = head;
        new_ptr = new_head.next;
        while (ptr) {
            if (ptr->random) {
                new_ptr->random = node_map[ptr->random];
            }
            new_ptr = new_ptr->next;
            ptr = ptr->next;
        }
        return new_head.next;
    }
};
