/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode *last = NULL;
        preorder(root, last);
    }
private:
    void preorder(TreeNode *node, TreeNode *&last) {
        if (!node) {
            return;
        }
        if (!node->left && !node->right) {
            last = node;
            return;
        }
        TreeNode *left_last = NULL, *right_last = NULL;
        TreeNode *left = node->left, *right = node->right;
        if (left) {
            preorder(left, left_last);
            node->left = NULL;
            node->right = left;
            last = left_last;
        }
        if (right) {
            preorder(right, right_last);
            if (left_last) {
                left_last->left = NULL;
                left_last->right = right;
            }
            last = right_last;
        }
    }
};
