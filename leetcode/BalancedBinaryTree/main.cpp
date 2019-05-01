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
    bool isBalanced(TreeNode* root) {
        bool balanced = true;
        height(root, balanced);
        return balanced;
    }

    int height(TreeNode *root, bool &balanced) {
        if (root == NULL) {
            return 0;
        }
        int left_height = height(root->left, balanced) + 1;
        int right_height = height(root->right, balanced) + 1;
        if (abs(left_height - right_height) > 1) {
            balanced = false;
        }
        return left_height > right_height ? left_height : right_height;
    }
};
