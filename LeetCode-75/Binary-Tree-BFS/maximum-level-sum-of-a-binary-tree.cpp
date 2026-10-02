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
    vector<vector<int>> bfss(TreeNode* root){
        vector<vector<int>> ans;
        if(root == nullptr){
            return ans;
        }
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            vector<int> level;
            int n = q.size();
            for(int i=0; i < n; i++){
                TreeNode* node = q.front();
                q.pop();
                level.push_back(node->val);
                if(node ->left)
                q.push(node->left);
                if(node->right)
                q.push(node->right);
            }
            ans.push_back(level);
        }
        return ans;
    }
    int maxLevelSum(TreeNode* root) {
        vector<vector<int>> levels = bfss(root);
        int maxi = INT_MIN, level = 0;
        for(int i=0;i<levels.size();i++){
            int sum = 0;
            for(int j = 0; j<levels[i].size();j++){
                sum += levels[i][j];
            }
            if(sum > maxi){
                maxi = sum;
                level = i+1;
            }
        }
        return level;
    }
};
