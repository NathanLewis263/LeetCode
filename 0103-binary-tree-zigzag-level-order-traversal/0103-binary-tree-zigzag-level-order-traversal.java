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
    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
        List<List<Integer>> ans = new ArrayList<>();
        if (root == null) return ans;
        
        Queue<TreeNode> q = new ArrayDeque<>();
        q.offer(root);
        boolean zig = true;
        
        while (!q.isEmpty()) {
            int len = q.size();
            List<Integer> level = new ArrayList<>(len);
            
            for (int i = 0; i < len; i++) {
                TreeNode node = q.poll();
                
                // collect value in zig or zag order
                if (zig) {
                    level.add(node.val);
                } else {
                    level.add(0, node.val);
                }
                
                // always enqueue left then right
                if (node.left  != null) q.offer(node.left);
                if (node.right != null) q.offer(node.right);
            }
            
            ans.add(level);
            zig = !zig;
        }
        
        return ans;
    }
}
