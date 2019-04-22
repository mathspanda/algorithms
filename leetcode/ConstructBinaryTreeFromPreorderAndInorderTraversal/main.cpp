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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return pre(preorder, 0, preorder.size() - 1,
                  inorder, 0, inorder.size() - 1);
    }
    
    TreeNode* pre(vector<int>& preorder, int preleft, int preright, 
                 vector<int>& inorder, int inleft, int inright) {
        if (preleft > preright || inleft > inright) {
            return NULL;
        }
        TreeNode *root = new TreeNode(preorder[preleft]);
        int index = 0;
        while (inorder[inleft + index] != preorder[preleft]) index++;
        root->left = pre(preorder, preleft + 1, preleft + 1 + index - 1, 
                        inorder, inleft, inleft + index - 1);
        root->right = pre(preorder, preleft + index + 1, preright,
                         inorder, inleft + index + 1, inright);
        return root;
    }
};
