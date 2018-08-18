/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public TreeNode invertTree(TreeNode root) {
        if (root == null)
            return null;
        else {
            TreeNode leftTreeNode = invertTree(root.left);
            TreeNode rightTreeNode = invertTree(root.right);
            root.left = rightTreeNode;
            root.right = leftTreeNode;
            return root;
        }
    }
}