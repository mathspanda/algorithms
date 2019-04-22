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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) {
            return res;
        }
        queue<TreeNode *> q;
        q.push(root);
        bool reverse = false;
        while (!q.empty()) {
            vector<int> l;
            int size = q.size();
            for (int i = 0; i < size; i++) {
                TreeNode *temp = q.front();
                q.pop();
                if (!reverse) {
                    l.push_back(temp->val);
                } else {
                    l.insert(l.begin(), temp->val);
                }    
                if (temp->left) q.push(temp->left);
                if (temp->right) q.push(temp->right);
            }
            reverse = !reverse;
            res.push_back(l);
        }
        return res;
    }
};
