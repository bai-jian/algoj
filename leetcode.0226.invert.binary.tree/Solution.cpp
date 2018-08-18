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
    TreeNode* invertTree(TreeNode* root) {
        if (root == NULL)
            return NULL;
        else {
            TreeNode* leftTreeNode = invertTree(root->left);
            TreeNode* rightTreeNode = invertTree(root->right);
            root->left = rightTreeNode;
            root->right = leftTreeNode;
            return root;
        }
    }
};