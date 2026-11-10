/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool dfs(TreeNode* root, TreeNode* curr, vector<TreeNode*> &path){
        if(root == nullptr)
        return false;

        path.push_back(root);
        if(root == curr)
        return true;
        if(dfs(root->left, curr, path) == true || dfs(root->right, curr, path) == true){
            return true;
        }
        path.pop_back();
        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> pathofp;
        vector<TreeNode*> pathofq;
        TreeNode* ans = root;
        dfs(root, p, pathofp);
        dfs(root, q, pathofq);
        for(int i=0;i<min(pathofp.size(), pathofq.size());i++){
            if(pathofp[i] == pathofq[i])
            ans = pathofp[i];
            else
            break;
        } 
        return ans;
    }
};
