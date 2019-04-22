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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode *> s;
        TreeNode *current = root;
        while (current != NULL || !s.empty()) {
            if (current != NULL) {
                res.push_back(current->val);
                if (current->right) {
                    s.push(current->right);
                }
                current = current->left;
            } else {
                current = s.top();
                s.pop();
            }
        }
        return res;
    }
};
