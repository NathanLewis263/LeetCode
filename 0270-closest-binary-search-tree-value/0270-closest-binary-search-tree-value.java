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
    public void inorder(TreeNode root, ArrayList<Integer> nums) {
        if (root == null) return;
        inorder(root.left, nums);
        nums.add(root.val);
        inorder(root.right, nums);
    }
    public int closestValue(TreeNode root, double target) {
        ArrayList<Integer> nums = new ArrayList<>();
        inorder(root, nums);
        int left = 0;
        int right = nums.size()-1;
        while (left < right){
            int mid = left + (right-left)/2;
            if (nums.get(mid) < target){
                left = mid+1;
            } else {
                right = mid;
            }
        }
        if (left > 0 && Math.abs(nums.get(left) - target) >= Math.abs(target - nums.get(left - 1))){
            return nums.get(left-1);
        }
        return nums.get(left);
    }
}