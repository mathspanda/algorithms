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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode *> s;
        TreeNode *current = root;
        while (current != NULL || !s.empty()) {
            if (current != NULL) {
                s.push(current);
                current = current->left;
            } else {
                current = s.top();
                s.pop();
                res.push_back(current->val);
                current = current->right;
            }
        }
        return res;
    }
};
