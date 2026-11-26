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
    int ans = 0;
    pair<int,int> helper(TreeNode* root){
        if(root == nullptr){
            return {0,0};
        }
        pair<int,int> leftpair = helper(root->left);
        pair<int,int> rightpair = helper(root->right);
        int left = 1+leftpair.second;
        int right = 1+rightpair.first;
        ans = max(ans, max(left, right));
        return {left, right};
    }
    int longestZigZag(TreeNode* root) {
        helper(root);
        return ans-1;
    }
};
