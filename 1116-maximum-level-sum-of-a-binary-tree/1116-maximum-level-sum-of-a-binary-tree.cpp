/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        if (!root){
            return 0;
        }
        queue<pair<TreeNode*,int>> queue; //val and level;
        queue.emplace(root,1);
       
        int currentLevel = 1;
        int levelSum = 0;
        int maxSum = INT_MIN;
        int maxLevel = 1;
       
        while (!queue.empty()){
            auto [node,level] = queue.front();
            queue.pop();
            
            if (level!=currentLevel){
                if (levelSum>maxSum){
                    maxLevel = currentLevel;
                    maxSum = levelSum;
                }
                levelSum = 0;
                currentLevel = level;
            }
            levelSum += node->val;
            if (node->right) {
                queue.emplace(node->right, level + 1);
            }
            if (node->left) {
                queue.emplace(node->left, level + 1);
            }
        }
        
        if (levelSum > maxSum) { //checks lastlevel 
            maxLevel = currentLevel;
        }
        
        return maxLevel;
    }
};