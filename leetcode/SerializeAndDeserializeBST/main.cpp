/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string data;
        bst_preorder(root, data);
        return data;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.length() == 0) { 
            return NULL;
        }
        int val = 0;
        vector<TreeNode *> node_vec;
        for (int i = 0; i < data.length(); i++) {
            if (data[i] == '*') {
                node_vec.push_back(new TreeNode(val));
                val = 0;
            } else {
                val = val * 10 + data[i] - '0';
            }
        }
        for (int i = 1; i < node_vec.size(); i++) {
            bst_insert(node_vec[0], node_vec[i]);
        }
        return node_vec[0];
    }
    
private:
    void bst_insert(TreeNode *root, TreeNode *node) {
        if (node->val < root->val) {
            if (root->left == NULL) {
                root->left = node;
            } else {
                bst_insert(root->left, node);
            }
        } else {
            if (root->right == NULL) {
                root->right = node;
            } else {
                bst_insert(root->right, node);
            }
        }
    }
    
    void bst_preorder(TreeNode *node, string &data) {
        if (!node) return;
        string str;
        int_to_string(node->val, str);
        data += str;
        bst_preorder(node->left, data);
        bst_preorder(node->right, data);
    }
    
    void int_to_string(int val, string &str) {
        string tmp;
        while (val) {
            tmp += val % 10 + '0';
            val = val / 10;
        }
        for (int i = tmp.length() - 1; i >= 0; i--) {
            str += tmp[i];
        }
        str += "*";
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
