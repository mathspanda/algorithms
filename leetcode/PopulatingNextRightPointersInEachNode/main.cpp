/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() {}

    Node(int _val, Node* _left, Node* _right, Node* _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
*/
class Solution {
public:
    Node* connect(Node* root) {
        if (root == NULL) {
            return NULL;
        }
        Node *cur = root, *next;
        while (cur->left) {
            next = cur;
            while (next) {
                next->left->next = next->right;
                if (next->next) {
                    next->right->next = next->next->left;
                }
                next = next->next;
            }
            cur = cur->left;
        }
        return root;
    }
};
