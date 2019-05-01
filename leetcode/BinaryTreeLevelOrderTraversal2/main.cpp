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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) {
            return res;
        }
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()) {
            vector<int> l;
            int size = q.size();
            for (int i = 0; i < size; i++) {
                TreeNode *temp = q.front();
                q.pop();
                l.push_back(temp->val);
                if (temp->left) q.push(temp->left);
                if (temp->right) q.push(temp->right);
            }
            res.insert(res.begin(), l);
        }
        return res;
    }
};
