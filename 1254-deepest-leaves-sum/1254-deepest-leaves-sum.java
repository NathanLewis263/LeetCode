/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public int deepestLeavesSum(TreeNode root) {
        Queue<TreeNode> q = new LinkedList<>();
        q.add(root);
        int sum = 0;
        while (!q.isEmpty()){
            int qSize = q.size();
            sum = 0;
            for (int i = 0;i<qSize;i++){
                if (q.peek().left != null){
                    q.add(q.peek().left);
                }
                if (q.peek().right != null){
                    q.add(q.peek().right);
                }

                sum += q.poll().val;
            }
        }
        return sum;
    }
}