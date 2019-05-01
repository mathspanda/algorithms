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
        Node *head = new Node(0, NULL, NULL, NULL);
        Node *layer = root;
        while (layer) {
            head->next = NULL;
            Node *cur = head;
            while (layer) {
                if (layer->left) {
                    cur->next = layer->left;
                    cur = cur->next;
                }
                if (layer->right) {
                    cur->next = layer->right;
                    cur = cur->next;
                }
                layer = layer->next;
            }
            layer = head->next;
        }
        return root;
    }
};
