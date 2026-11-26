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
    void helper(TreeNode* root, int targetSum, long long sum, int &ans){
        if(root == nullptr){
            return;
        }
        sum += root->val;
        if(sum == targetSum){
            ans++;
        }
        helper(root->left, targetSum, sum, ans);
        helper(root->right, targetSum, sum, ans);
    }
    int pathSum(TreeNode* root, int targetSum) {
        if(root == nullptr) return 0;
        int ans = 0;
        helper(root, targetSum, 0, ans);
        ans += pathSum(root->left, targetSum);
        ans += pathSum(root->right, targetSum);
        return ans;
    }
};
