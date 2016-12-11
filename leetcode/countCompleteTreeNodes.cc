// Copyright [2016] <Huang Jiaming>
/**
 * leetcode 222.Count Complete Tree Nodes
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
 public:
    int countNodes(TreeNode* root) {
        if (!root)
            return 0;
        int l = 0, r = 0;
        TreeNode *lt = root, *rt = root;
        while (lt) {
            l++;
            lt = lt->left;
        }
        while (rt) {
            r++;
            rt = rt->right;
        }
        if (l == r) {
            return pow(2, l) - 1;
        } else {
            return 1 + countNodes(root->left) + countNodes(root->right);
        }
    }

};
