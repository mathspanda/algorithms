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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        queue<pair<TreeNode*, int>> q;
        if (root) {
            q.push(make_pair(root, 0));
        }
        while (!q.empty()) {
            TreeNode *node = q.front().first;
            int layer = q.front().second;
            q.pop();
            if (res.size() <= layer) {
                res.push_back(node->val);
            } else {
                res[layer] = node->val;
            }
            if (node->left) {
                q.push(make_pair(node->left, layer + 1));
            }
            if (node->right) {
                q.push(make_pair(node->right, layer + 1));
            }
        }
        return res;
    }
};
