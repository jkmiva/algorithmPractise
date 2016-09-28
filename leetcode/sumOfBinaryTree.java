/**
 * Huang Jiaming
 * Sep 28, 2016
 * Saskatoon, Canada
 *
 * Compute sum of numbers represented by
 * each branch of a binary tree.
 **/

 public class TreeNode {
     int val;
     TreeNode left;
     TreeNode right;
     TreeNode(int x) { val = x; }
 }
 */
public class Solution {

    public int sumNumbers(TreeNode root) {
        return sum(root,0);
    }

    public int sum(TreeNode root, int s) {  // s is sum of last level, initialize to 0
        if (root == null)
            return 0;
        if (root.left == null && root.right == null)
            return root.val + 10*s;

        return sum(root.left, s*10 + root.val) + sum(root.right, s*10 + root.val);
    }
}
