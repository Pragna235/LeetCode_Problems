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
    Map<String,Integer> map=new HashMap<>();
    List<TreeNode> res=new ArrayList<>();
    public List<TreeNode> findDuplicateSubtrees(TreeNode root) {
        helper(root);
        return res;
    }
    public String helper(TreeNode root){
        if(root==null) return "";
        String left= helper(root.left);
        String right= helper(root.right);
        String curr= root.val +" "+left +" "+ right;
        map.put(curr, map.getOrDefault(curr, 0)+ 1);
        if(map.get(curr) == 2)
            res.add(root);
        return curr;
    }
}
