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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        if (!root){
            return result;
        }
        queue<pair<TreeNode*,int>> queue; //val and level;
        queue.emplace(root,0);
        int currentLevel = -1;
        while (!queue.empty()){
            auto [node,level] = queue.front();
            queue.pop();
            if (level>currentLevel){
                result.push_back(node->val);
                currentLevel = level;
            }
            if (node->right) {
                queue.emplace(node->right, level + 1);
            }
            if (node->left) {
                queue.emplace(node->left, level + 1);
            }
        }
        return result;
    }
};