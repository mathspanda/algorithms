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
// Copy and Construct.
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) {
            return NULL;
        }

        Node *ptr = head;
        while (ptr) {
            Node *next = ptr->next;
            ptr->next = new Node(ptr->val, next, NULL);
            ptr = next;
        }

        Node *odd = head;
        while (odd) {
            Node *even = odd->next;
            Node *odd_random = odd->random;
            if (odd_random) {
                Node *even_random = odd_random->next;
                even->random = even_random;
            }
            odd = even->next;
        }

        Node *result = head->next;
        odd = head;
        Node *even = head->next;
        while (odd) {
            Node *next = even->next;
            if (next) {
                even->next = next->next;
                even = next->next;
            }
            odd->next = next;
            odd = next;
        }
        return result;
    }
};

