struct BSTNode {
    int val;
    int count;
    BSTNode *left, *right;
    BSTNode(int x): val(x), count(0), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> res;
        vector<BSTNode *> node_vec;
        for (int i = nums.size() - 1; i >= 0; i--) {
            res.push_back(0);
            node_vec.push_back(new BSTNode(nums[i]));
        }
        for (int i = 1; i < nums.size(); i++) {
            int count_small = 0;
            bst_insert(node_vec[0], node_vec[i], count_small);
            res[nums.size()-i-1] = count_small;
        }
        return res;
    }
private:
    void bst_insert(BSTNode *root, BSTNode *node, int &count_small) {
        if (node->val <= root->val) {
            root->count++;
            if (root->left == NULL) {
                root->left = node;
            } else {
                bst_insert(root->left, node, count_small);
            }
        } else {
            count_small += root->count + 1;
            if (root->right == NULL) {
                root->right = node;
            } else {
                bst_insert(root->right, node, count_small);
            }
        }
    }
};
