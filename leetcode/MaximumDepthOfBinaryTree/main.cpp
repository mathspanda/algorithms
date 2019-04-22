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
    int maxDepth(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        int left_max = maxDepth(root->left) + 1;
        int right_max = maxDepth(root->right) + 1;
        return left_max > right_max ? left_max : right_max;
    }
};
