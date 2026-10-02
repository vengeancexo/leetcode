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
    vector<int> v1;
    vector<int> v2;
    void helper(TreeNode* root, vector<int> &v){
        if(root == nullptr){
            return;
        }
        if (root->left == nullptr && root->right == nullptr) {
            v.push_back(root->val);
            return;
        }
        helper(root->left, v);
        helper(root->right, v);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        helper(root1, v1);
        helper(root2, v2);
        return v1 == v2;
    }
};
