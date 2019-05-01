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
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            Node *prev = NULL;
            int size = q.size();
            for (int i = 0; i < size; i++) {
                Node *cur = q.front();
                q.pop();
                if (prev == NULL) {
                    prev = cur;
                } else {
                    prev->next = cur;
                    prev = cur;
                }
                if (cur->left) q.push(cur->left);
                if (cur->right) q.push(cur->right);
            }
        }
        return root;
    }
};
