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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        if (!root) {
            return res;
        }
        stack<TreeNode *> s;
        s.push(root);
        TreeNode *prev = NULL;
        while (!s.empty()) {
            TreeNode *temp = s.top();
            if (!temp->left && !temp->right) {
                s.pop();
                res.push_back(temp->val);
                prev = temp;
            } else if (prev && (temp->left == prev || temp->right == prev)) {
                s.pop();
                res.push_back(temp->val);
                prev = temp;
            } else {
                if (temp->right) s.push(temp->right);
                if (temp->left) s.push(temp->left);
            }
        }
        return res;
    }
};
