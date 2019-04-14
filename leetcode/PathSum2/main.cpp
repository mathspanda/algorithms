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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        vector<int> path;
        int path_value = 0;
        preTraverse(root, res, path, path_value, sum);
        return res;
    }
private:
    void preTraverse(TreeNode *node, 
                     vector<vector<int>> &res, 
                     vector<int> &path, 
                     int &path_value, int sum) {
        if (!node) {
            return;
        }
        path_value += node->val;
        path.push_back(node->val);
        if (!node->left && !node->right && path_value == sum) {
            res.push_back(path);
        }
        preTraverse(node->left, res, path, path_value, sum);
        preTraverse(node->right, res, path, path_value, sum);
        path_value -= node->val;
        path.pop_back();
    }
};
