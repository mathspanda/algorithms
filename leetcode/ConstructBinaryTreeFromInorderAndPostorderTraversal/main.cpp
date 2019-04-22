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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return post(postorder, 0, postorder.size() - 1,
                   inorder, 0, inorder.size() - 1);
    }
    
    TreeNode *post(vector<int>& postorder, int postleft, int postright,
                  vector<int>& inorder, int inleft, int inright) {
        if (postleft > postright || inleft > inright) {
            return NULL;
        }
        TreeNode *root = new TreeNode(postorder[postright]);
        int index = 0;
        while (inorder[inleft + index] != postorder[postright]) index++;
        root->left = post(postorder, postleft, postleft + index - 1,
                         inorder, inleft, inleft + index - 1);
        root->right = post(postorder, postleft + index, postright - 1,
                          inorder, inleft + index + 1, inright);
        return root;
    }
};
