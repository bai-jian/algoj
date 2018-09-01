import java.util.*;

public class BinaryTree {
    class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;
        TreeNode(int x) { val = x; }
    }

    public List<Integer> preorderTraversal(TreeNode root) {
        if (root == null)
            return Collections.EMPTY_LIST;
        else {
            List<Integer> list = new ArrayList<>();
            list.add(root.val);
            list.addAll(preorderTraversal(root.left));
            list.addAll(preorderTraversal(root.right));
            return list;
        }
    }

    public List<Integer> inorderTraversal(TreeNode root) {
        if (root == null)
            return Collections.EMPTY_LIST;
        else {
            List<Integer> list = new ArrayList<>();
            list.addAll(inorderTraversal(root.left));
            list.add(root.val);
            list.addAll(inorderTraversal(root.right));
            return list;
        }
    }

    public List<Integer> postorderTraversal(TreeNode root) {
        if (root == null)
            return Collections.EMPTY_LIST;
        else {
            List<Integer> list = new ArrayList<>();
            list.addAll(postorderTraversal(root.left));
            list.addAll(postorderTraversal(root.right));
            list.add(root.val);
            return list;
        }
    }

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
